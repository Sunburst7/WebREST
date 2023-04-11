/*
 * @Author: HH
 * @Date: 2023-03-31 23:01:35
 * @LastEditTime: 2023-04-08 23:43:10
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

Channel::~Channel()
{
    
}

void Channel::update()
{ 
    loop_->update_channel(*this); 
}

void Channel::handle_event()
{
    printf("Channel:: read cb: %d\n", read_cb_);
    if ( revents_ & EPOLLIN ) 
        read_cb_();
    else if (revents_ & EPOLLOUT )
        write_cb_();
    else {

    }
}

#endif
