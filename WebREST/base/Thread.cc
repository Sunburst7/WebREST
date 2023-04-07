/*
 * @Author: HH
 * @Date: 2023-04-05 01:16:12
 * @LastEditTime: 2023-04-06 19:01:00
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/WebREST/base/Thread.cc
 */

#ifndef WebREST_THREAD_CC_
#define WebREST_THREAD_CC_

#include "Thread.h"

using namespace WebREST;

void Thread::run_in_thread()
{
    latch_.count_down();
    func_();
}

void Thread::start_thread()
{
    assert(!started_);
    started_ = true;

    thread_ = std::move(std::thread(&Thread::run_in_thread, this));
    latch_.wait();
}

#endif