/*
 * @Author: sunburst7 1064658281@qq.com
 * @Date: 2023-04-13 22:50:57
 * @LastEditors: sunburst7 1064658281@qq.com
 * @LastEditTime: 2023-04-14 00:20:55
 * @FilePath: /WebREST/WebREST/core/timer.h
 * @Description: 封装定时器
 * 
 * Copyright (c) 2023 by sunburst7 1064658281@qq.com, All Rights Reserved. 
 */
#ifndef WebREST_TIMER_H_
#define WebREST_TIMER_H_

#include "timestamp.h"
#include "non_copyable.h"
#include "callback.h"

namespace WebREST {

class Timer: NonCopyable
{
public:
    Timer(TimeStamp expiration, TimerCallback&& cb, double interval);

    // getter
    TimeStamp expiration() const { return expiration_; }
    bool repeat() const { return repeat_; } 

    void restart(TimeStamp now) { expiration_ = TimeStamp::add_time(now, interval_); }

    void run() const { cb_(); }

private:
    TimeStamp expiration_;      // 到期时间戳
    TimerCallback cb_;
    double interval_;           // 一个定时器任务的持续时间
    bool repeat_;
};

} // namespace WebREST

#endif