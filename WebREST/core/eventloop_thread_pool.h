/*
 * @Author: HH
 * @Date: 2023-04-05 17:45:17
 * @LastEditTime: 2023-04-06 18:30:38
 * @LastEditors: HH
 * @Description: 一个简单的轮转线程池 
 * @FilePath: /WebREST/WebREST/core/eventloop_thread_pool.h
 */

#ifndef WebREST_EVENTLOOP_THREAD_POOL_H_
#define WebREST_EVENTLOOP_THREAD_POOL_H_

#include <vector>
#include <memory>

#include "non_copyable.h"

namespace WebREST {

class EventLoop;
class EventLoopThread;

class EventLoopThreadPool: NonCopyable
{
public:
    EventLoopThreadPool(EventLoop* base_loop);
    ~EventLoopThreadPool();

    void set_thread_num(int num) { thread_num_ = num; }

    // pool的初始化函数
    void start();

    EventLoop* get_next_loop();

private:
    EventLoop* base_loop_;
    int thread_num_;
    int next_;              // 用于在轮询中寻找下一个
    std::vector<std::unique_ptr<EventLoopThread>> threads_;
    std::vector<EventLoop*> loops_;
};

} // namespace WebREST

#endif