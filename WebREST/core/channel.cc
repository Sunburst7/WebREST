/*
 * @Author: HH
 * @Date: 2023-03-31 23:01:35
 * @LastEditTime: 2023-04-11 23:32:11
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/WebREST/core/channel.cc
 */

#ifndef WebREST_CHANNEL_CC_
#define WebREST_CHANNEL_CC_

#include "channel.h"
#include "eventloop.h"

using namespace WebREST;

Channel::Channel(EventLoop* loop, int fd): 
    loop_(loop), 
    fd_(fd),
    events_(0),
    revents_(0),
    state_(kNew)
{

}

Channel::~Channel() = default;

void Channel::update()
{ 
    loop_->update_channel(*this); 
}

void Channel::remove()
{
    loop_->remove_channel(*this);
}

void Channel::handle_event()
{
    printf("[DEBUG] Channel::handle_event  revents=%d\n", revents_);
    if ( revents_ & (EPOLLIN | EPOLLPRI | EPOLLRDHUP) ) 
        if ( read_cb_ )
            read_cb_();
    if (revents_ & EPOLLOUT )
        if ( write_cb_ )
            write_cb_();
}

#endif
