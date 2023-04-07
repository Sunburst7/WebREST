/*
 * @Author: HH
 * @Date: 2023-04-05 00:55:53
 * @LastEditTime: 2023-04-05 01:14:18
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/WebREST/base/countdown_latch.cc
 */
#ifndef WebREST_COUNTDOWN_LATCH_CC_
#define WebREST_COUNTDOWN_LATCH_CC_

#include "countdown_latch.h"

using namespace WebREST;

void CountDownLatch::count_down()
{
    std::lock_guard<std::mutex> lock(mutex_);
    count_--;
    if (count_ == 0)
        cv_.notify_all();
}

void CountDownLatch::wait()
{
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [this]{ return count_ == 0; });
}

#endif