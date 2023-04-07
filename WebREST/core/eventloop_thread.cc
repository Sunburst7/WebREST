/*
 * @Author: HH
 * @Date: 2023-04-05 03:10:56
 * @LastEditTime: 2023-04-06 18:27:56
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/WebREST/core/eventloop_thread.cc
 */
#ifndef WebREST_EVENTLOOP_THREAD_CC_
#define WebREST_EVENTLOOP_THREAD_CC_

#include "eventloop_thread.h"
#include "eventloop.h"

using namespace WebREST;

EventLoopThread::EventLoopThread():
    loop_(nullptr),
    thread_(std::bind(&EventLoopThread::thread_func, this)),
    mutex_(),
    cv_()
{

}

EventLoopThread::~EventLoopThread()
{

}

EventLoop* EventLoopThread::start_loop()
{
    assert(!thread_.is_started());
    thread_.start_thread();

    EventLoop* new_loop;
    {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this]{ return loop_ != nullptr; });    // 等待IO线程创建好EventLoop
        new_loop = loop_;
    }
    return new_loop;
}

void EventLoopThread::thread_func()
{   
    // 由于EventLoop的生命期与thread_func的作用域相同，
    // 因此在threadFunc()退出之后这个指针就失效了
    EventLoop loop;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        loop_ = &loop;
        cv_.notify_one();
    }

    loop.loop();
    std::lock_guard<std::mutex> lock(mutex_);
    loop_ = nullptr;
}

#endif
