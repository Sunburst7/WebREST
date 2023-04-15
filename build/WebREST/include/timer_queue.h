/*
 * @Author: sunburst7 1064658281@qq.com
 * @Date: 2023-04-13 22:47:35
 * @LastEditors: sunburst7 1064658281@qq.com
 * @LastEditTime: 2023-04-14 01:27:39
 * @FilePath: /WebREST/WebREST/core/timer_queue.h
 * @Description: 小根堆定时器队列
 * 
 * Copyright (c) 2023 by sunburst7 1064658281@qq.com, All Rights Reserved. 
 */
#ifndef WebREST_TIMER_QUEUE_H_
#define WebREST_TIMER_QUEUE_H_

#include "non_copyable.h"
#include "timestamp.h"
#include "timer.h"
#include "callback.h"

#include <set>
#include <algorithm>
#include <vector>
#include <memory>
#include <functional>

namespace WebREST {

class EventLoop;
class Channel;

class TimerQueue : NonCopyable{
public:
    TimerQueue(EventLoop* loop);
    ~TimerQueue();
    
    void add_timer(TimeStamp timestamp, TimerCallback& cb, double interval);
    // void cancel();
private:
    using TimerEntry = std::pair<TimeStamp, Timer*>;    // 最好不要用unique_ptr， 后面涉及到复制的操作，unique_ptr无复制构造函数

    void add_timer_in_loop(Timer* timer);
    // void cancelInLoop(TimerId timerId);

    void handle_read();                 // called when timerfd alarms, move out all expired timers
    void reset();                       // 重置active_timers队列
    void reset_timerfd(Timer* timer);   // 根据timer重新设置timerfd的超时时间
    bool insert(Timer* timer);          // 插入到set中

    EventLoop* loop_;
    int timerfd_;
    std::unique_ptr<Channel> channel_;
    std::set<TimerEntry> timers_;
    std::vector<TimerEntry> active_timers_;
};

} // namespace WebREST

#endif