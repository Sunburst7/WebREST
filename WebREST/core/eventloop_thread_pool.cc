/*
 * @Author: HH
 * @Date: 2023-04-05 17:45:29
 * @LastEditTime: 2023-04-06 18:24:06
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/WebREST/core/eventloop_thread_pool.cc
 */
#ifndef WebREST_EVENTLOOP_THREAD_POOL_CC_
#define WebREST_EVENTLOOP_THREAD_POOL_CC_

#include "eventloop_thread_pool.h"
#include "eventloop.h"
#include "eventloop_thread.h"

using namespace WebREST;

EventLoopThreadPool::EventLoopThreadPool(EventLoop* base_loop):
    base_loop_(base_loop),
    thread_num_(0),
    next_(0),
    threads_(),
    loops_()
{

}

void EventLoopThreadPool::start()
{
    //baseLoop_->assertInLoopThread();
    for (int i = 0; i < thread_num_; i++)
    {
        EventLoopThread* t = new EventLoopThread();
        threads_.emplace_back(t);
        loops_.emplace_back(t->start_loop());
    }
}


EventLoopThreadPool::~EventLoopThreadPool()
{
    
}

EventLoop* EventLoopThreadPool::get_next_loop()
{
    //baseLoop_->assertInLoopThread();
    EventLoop* ret = base_loop_;
    if (!loops_.empty())
    {
        ret = loops_[next_];
        next_ = (next_ + 1) % thread_num_; // 循环访问
    }
    return ret;
}

#endif