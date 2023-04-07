/*
 * @Author: HH
 * @Date: 2023-04-05 03:10:48
 * @LastEditTime: 2023-04-06 18:28:02
 * @LastEditors: HH
 * @Description: 提供了对应eventloop和thread的封装，意为I/O线程类
 * @FilePath: /WebREST/WebREST/core/eventloop_thread.h
 */
#ifndef WebREST_EVENTLOOP_THREAD_H_
#define WebREST_EVENTLOOP_THREAD_H_

#include <mutex>
#include <condition_variable>

#include "non_copyable.h"
#include "Thread.h"

namespace WebREST {

class EventLoop;

class EventLoopThread : NonCopyable {
public:
    EventLoopThread();
    ~EventLoopThread();
    // 返回新IO线程中EventLoop对象的地址，主线程需要等待IO线程创建完成才能获取
    EventLoop* start_loop(); 
private:
    // 传入thread_构造函数中
    void thread_func(); 
    
    EventLoop* loop_;
    Thread thread_;
    std::mutex mutex_;
    std::condition_variable cv_;
};

} // namespace WebREST

#endif