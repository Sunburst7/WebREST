/*
 * @Author: sunburst7 1064658281@qq.com
 * @Date: 2023-04-13 22:51:04
 * @LastEditors: sunburst7 1064658281@qq.com
 * @LastEditTime: 2023-04-14 00:20:59
 * @FilePath: /WebREST/WebREST/core/timer.cc
 * @Description: 
 * 
 * Copyright (c) 2023 by sunburst7 1064658281@qq.com, All Rights Reserved. 
 */
#ifndef WebREST_TIMER_CC_
#define WebREST_TIMER_CC_

#include "timer.h"

using namespace WebREST;

Timer::Timer(TimeStamp expiration, TimerCallback&& cb, double interval = 0.0):
    expiration_(expiration),
    cb_(std::move(cb)),
    interval_(interval),
    repeat_(interval_ > 0.0)
{

}

#endif
