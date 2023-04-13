/*
 * @Author: HH
 * @Date: 2023-03-31 01:40:11
 * @LastEditTime: 2023-04-13 00:15:28
 * @LastEditors: sunburst7 1064658281@qq.com
 * @Description: 每个线程的主要事件循环，通过不断调用loop函数实现
 * @FilePath: /Enhance_Tiny_muduo/WebREST/core/eventloop.h
 */

#ifndef WebREST_EVENTLOOP_H_
#define WebREST_EVENTLOOP_H_

#include <unistd.h>
#include <functional>
#include <assert.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <thread>
#include <mutex>
#include <vector>
#include <memory>
#include <signal.h>

#include "epoller.h"

namespace WebREST {

class Channel;
class Epoller;

class EventLoop : NonCopyable{
public:
    using Func =  std::function<void()>;

    EventLoop();
    ~EventLoop();
    
    // static EventLoop* get_eventloop_of_current_thread();

    void loop();
    void update_channel(Channel& channel) { epoller_->update_channel(channel); };
    void remove_channel(Channel& channel) { epoller_->remove_channel(channel); }

    bool is_in_loop_thread() const 
    { return thread_id_ == std::this_thread::get_id(); }

    std::thread::id thread_id() const 
    { return thread_id_; }

    void queue_in_loop(const Func& cb);
    // 如果用户在当前IO线程调用这个函数，回调会同步进行；
    // 如果用户在其他线程调用runInLoop()，cb会被加入队列，IO线程会被唤醒来调用这个Functor。
    void run_in_loop(const Func& cb);
    // void assert_in_loop_thread();
    

private:
    using ChannelList = std::vector<Channel*>;
    
    // 用于唤醒阻塞在epoller.poll()上的IO线程
    // 在需要唤醒的时候，其他线程往管道里写一个字节，这样IO线程就从IOmultiplexing阻塞调用中返回。
    void wakeup();
    // wakeup_channel的read_callback
    void handle_read();
    void do_pending_func();
    
    std::thread::id thread_id_;
    std::unique_ptr<Epoller> epoller_;
    ChannelList active_channels_;

    // 用于唤醒阻塞在epoller.poll()上的IO线程
    // wakeupChannel_用于处理wakeupFd_上的readable事件，将事件分发至handleRead()函数。
    int wakeup_fd_;
    std::unique_ptr<Channel> wakeup_channel_;

    // 其中只有pendingFunctors_暴露给了其他线程，因此用mutex保护。
    bool calling_pending_func_;
    std::mutex mutex_;
    std::vector<Func> pending_func_;
};


} // namespace WebREST

#endif