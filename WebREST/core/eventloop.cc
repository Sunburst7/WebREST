/*
 * @Author: HH
 * @Date: 2023-03-31 03:38:32
 * @LastEditTime: 2023-04-03 23:37:24
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/WebREST/core/eventloop.cc
 */

#ifndef WebREST_EVENTLOOP_CC_
#define WebREST_EVENTLOOP_CC_

#include "eventloop.h"
#include "channel.h"
#include "epoller.h"

using namespace WebREST;

__thread EventLoop* t_eventloop_in_this_thread = 0; // current thread own EventLoop address, lifecycle is same as EventLoop

EventLoop::EventLoop():
    epoller_(new Epoller()),
    weakup_fd_(0)
{

}

EventLoop::~EventLoop()
{

}


void EventLoop::loop()
{ 
    printf("EventLoop:: %d start looping\n", this);
    while (1) {
        epoller_->poll(active_channels_);
        if (active_channels_.size())
            printf("EventLoop:: active channel size: %d\n", active_channels_.size());
        for ( const auto& channel : active_channels_ ) 
        {
            printf("EventLoop:: eventloop: channel_fd is %d\n", channel->fd());
            channel->handle_event();
        }
        active_channels_.clear();
    }
    printf("EEventLoop:: %d stop looping\n", this);
}

#endif
