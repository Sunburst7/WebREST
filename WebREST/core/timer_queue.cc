/*
 * @Author: sunburst7 1064658281@qq.com
 * @Date: 2023-04-13 22:47:47
 * @LastEditors: sunburst7 1064658281@qq.com
 * @LastEditTime: 2023-04-14 01:28:53
 * @FilePath: /WebREST/WebREST/core/timer_queue.cc
 * @Description: 定时器队列
 * 
 * Copyright (c) 2023 by sunburst7 1064658281@qq.com, All Rights Reserved. 
 */
#ifndef WebREST_TIMER_QUEUE_CC_
#define WebREST_TIMER_QUEUE_CC_

#include <sys/timerfd.h>

#include "timer_queue.h"
#include "eventloop.h"
#include "channel.h"


using namespace WebREST;

TimerQueue::TimerQueue(EventLoop* loop):
    loop_(loop),
    timerfd_(::timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK | TFD_CLOEXEC)),
    channel_(new Channel(loop_, timerfd_))
{
    channel_->set_read_callback(std::bind(&TimerQueue::handle_read, this));
    channel_->enable_reading();
}

TimerQueue::~TimerQueue()
{
    channel_->disbale_all();
    channel_->remove();
    ::close(timerfd_);

    for (const auto& entry: timers_)
        delete entry.second;
}
    
void TimerQueue::add_timer(TimeStamp timestamp, TimerCallback& cb, double interval)
{
    Timer* timer = new Timer(timestamp, std::move(cb), interval);
    loop_->run_in_loop(std::bind(&TimerQueue::add_timer_in_loop, this, timer));
}

void TimerQueue::add_timer_in_loop(Timer* timer)
{
    // assert(loop_->is_in_loop());
    bool reset_immediately = insert(timer);
    if (reset_immediately)
        reset_timerfd(timer);
}

void TimerQueue::handle_read()
{
    // 唤醒
    uint64_t read_byte; // containing the number of expirations that have occurred
    ssize_t readn = ::read(timerfd_, &read_byte, sizeof read_byte);
    if (readn != sizeof(read_byte))
        printf("[DEBUG] TimerQueue::handle_read read system error\n");
    
    // 找出所有到期时间小于当前时间的定时器，并复制到active_timer_中
    active_timers_.clear();
    auto end = timers_.lower_bound(
        TimerEntry(TimeStamp::now(), reinterpret_cast<Timer*>(UINTPTR_MAX)) // 第二个参数表示64bit机器的最大地址，能够找出所有处于相同时刻的定时器
    );
    active_timers_.insert(active_timers_.end(), timers_.begin(), end);
    timers_.erase(timers_.begin(), end);

    for (const auto& entry: active_timers_)
        entry.second->run();
    reset();
}

void TimerQueue::reset()
{
    for (auto& entry: active_timers_)
    {
        if (entry.second->repeat())
        {
            entry.second->restart(TimeStamp::now());
            insert(entry.second);
        }
        else
        {
            delete entry.second;
        }
    }
    // 更新timer的超时时间
    if (!timers_.empty())
        reset_timerfd(timers_.begin()->second);
}

void TimerQueue::reset_timerfd(Timer* timer)
{
    struct itimerspec new_;
    struct itimerspec old_;
    memset(&new_, 0, sizeof new_), memset(&old_, 0, sizeof old_);

    int64_t micro_seconds_diff = timer->expiration().micro_seconds() - TimeStamp::now().micro_seconds();
    if (micro_seconds_diff < 100)
        micro_seconds_diff = 100;
    
    new_.it_value.tv_sec = static_cast<time_t>(micro_seconds_diff / TimeStamp::kMicrosecondToSecond);
    new_.it_value.tv_nsec = static_cast<long>((micro_seconds_diff % TimeStamp::kMicrosecondToSecond) * 1000);   // 纳秒 
    int ret = ::timerfd_settime(timerfd_, 0, &new_, &old_);
    assert(ret != -1);
}

bool TimerQueue::insert(Timer* timer)
{
    bool reset_immediately = false;
    // 是否插入的定时器触发过期时间是小于目前set中最小的时间，是的话需要重新去设置超时时间 
    if (timers_.empty() || timer->expiration() < timers_.begin()->first)
        reset_immediately = true;
    
    timers_.emplace(TimerEntry(timer->expiration(), timer));
    return reset_immediately;
}

#endif