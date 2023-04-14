/*
 * @Author: sunburst7 1064658281@qq.com
 * @Date: 2023-04-13 22:03:38
 * @LastEditors: sunburst7 1064658281@qq.com
 * @LastEditTime: 2023-04-14 01:38:34
 * @FilePath: /WebREST/WebREST/base/timestamp.cc
 * @Description: 
 * 
 * Copyright (c) 2023 by sunburst7 1064658281@qq.com, All Rights Reserved. 
 */

#ifndef WebREST_TIMESTAMP_CC_
#define WebREST_TIMESTAMP_CC_

#include "timestamp.h"

using namespace WebREST;

std::string TimeStamp::to_format_string() const
{
    char buf[64]{0};
    time_t seconds = static_cast<time_t>(micro_seconds_ / kMicrosecondToSecond);
    struct tm tm_time;
    localtime_r(&seconds, &tm_time);
    int microseconds = static_cast<int>(micro_seconds_ % kMicrosecondToSecond);
    snprintf(buf, sizeof buf, "%4d%02d%02d %02d:%02d:%02d.%06d", 
        tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday, tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec, microseconds);

    return buf;
}

TimeStamp TimeStamp::now()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return TimeStamp(time.tv_sec * kMicrosecondToSecond + time.tv_usec);
}

TimeStamp TimeStamp::add_time(TimeStamp t, double seconds)
{
    int64_t addition_microseconds = static_cast<int64_t>(seconds) * kMicrosecondToSecond;
    return TimeStamp(t.micro_seconds() + addition_microseconds);
}

#endif