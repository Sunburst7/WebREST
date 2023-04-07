/*
 * @Author: HH
 * @Date: 2023-03-31 03:38:32
 * @LastEditTime: 2023-04-05 04:52:55
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/WebREST/core/eventloop.cc
 */

#ifndef WebREST_EVENTLOOP_CC_
#define WebREST_EVENTLOOP_CC_

#include "eventloop.h"
#include "channel.h"
#include "epoller.h"

using namespace WebREST;

__thread EventLoop* t_eventloop_in_this_thread = 0; // 线程内变量 当前线程的eventloop addr

EventLoop::EventLoop():
    thread_id_(std::this_thread::get_id()),
    epoller_(new Epoller()),
    wakeup_fd_(::eventfd(0, EFD_NONBLOCK)),
    wakeup_channel_(new Channel(this, wakeup_fd_))
{
    wakeup_channel_->set_read_callback(
        std::bind(&EventLoop::handle_read, this));
    wakeup_channel_->enable_reading();
}

EventLoop::~EventLoop()
{

}

void EventLoop::wakeup()
{
  uint64_t one = 1;
  ssize_t n = ::write(wakeup_fd_, &one, sizeof one);
  if (n != sizeof one)
  {
    printf("EventLoop::wakeup() write %d bytes instead of 8\n", n);
  }
}

void EventLoop::handle_read()
{
    uint64_t one = 1; // 64位代表8字节
    ssize_t n = ::read(wakeup_fd_, &one, sizeof(one));
    if (n != sizeof one)
        printf("EventLoop::handle_read() reads %d bytes instead of 8\n", n);
}

void EventLoop::do_pending_func()
{
    std::vector<Func> tmp_functors;
    calling_pending_func_ = true;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        tmp_functors.swap(pending_func_);
    }
    for (const Func& func: tmp_functors)
        func();
    calling_pending_func_ = false;
}

void EventLoop::loop()
{ 
    printf("EventLoop:: %d start looping\n", this);
    while (1) {
        epoller_->poll(active_channels_);
        if (active_channels_.size())
            printf("EventLoop:: active channel size: %d\n", active_channels_.size());
        for ( const auto& channel : active_channels_ ) 
        {
            printf("EventLoop:: eventloop: channel_fd is %d\n", channel->fd());
            channel->handle_event();
        }
        active_channels_.clear();
        do_pending_func();
    }
    printf("EventLoop:: %d stop looping\n", this);
}

void EventLoop::queue_in_loop(const Func& cb)
{
    {
        std::lock_guard<std::mutex> lock(mutex_);
        pending_func_.emplace_back(cb);
    }
    // 1 如果调用queueInLoop()的线程不是IO线程
    // 2 如果在IO线程调用queueInLoop()，而此时正在调用pending functor，
    //      2.1 (由于doPendingFunctors()调用的Functor可能再调用queueInLoop(cb)，这时queueInLoop()就必须wakeup()，否则这些新加的cb就不能被及时调用了。)
    // => 必须唤醒
    // 换句话说，只有在IO线程的事件回调中调用queue_in_loop()才无须wakeup()。
    if ( !is_in_loop_thread() || calling_pending_func_ )
        wakeup();
}

void EventLoop::run_in_loop(const Func& cb)
{
    if (is_in_loop_thread())
        cb();
    else
        queue_in_loop(std::move(cb));
}

#endif
