/*
 * @Author: sunburst7 1064658281@qq.com
 * @Date: 2023-04-13 22:03:30
 * @LastEditors: sunburst7 1064658281@qq.com
 * @LastEditTime: 2023-04-14 01:38:27
 * @FilePath: /WebREST/WebREST/base/timestamp.h
 * @Description: 时间戳类
 * 
 * Copyright (c) 2023 by sunburst7 1064658281@qq.com, All Rights Reserved. 
 */
#ifndef WebREST_TIMESTAMP_H_
#define WebREST_TIMESTAMP_H_

#include <stdio.h>
#include <sys/time.h>
#include <string>

namespace WebREST {

class TimeStamp {
public:
    static const int kMicrosecondToSecond = 1000 * 1000;
    TimeStamp(): micro_seconds_(0) {}
    explicit TimeStamp(int64_t micro_seconds): micro_seconds_(micro_seconds) {}

    int64_t micro_seconds() const { return micro_seconds_; }

    bool operator<(const TimeStamp& rhs) const { return micro_seconds_ < rhs.micro_seconds(); }
    bool operator==(const TimeStamp& rhs) const { return micro_seconds_ == rhs.micro_seconds(); }
    
    std::string to_format_string() const;

    static TimeStamp now();
    static TimeStamp add_time(TimeStamp t, double seconds);

private:
    int64_t micro_seconds_;
};

} // namespace WebREST

#endif