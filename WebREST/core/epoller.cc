/*
 * @Author: HH
 * @Date: 2023-04-01 18:27:11
 * @LastEditTime: 2023-04-08 23:59:55
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/WebREST/core/epoller.cc
 */

#ifndef WebREST_EPOLLER_CC_
#define WebREST_EPOLLER_CC_

#include "epoller.h"
#include "channel.h"

using namespace WebREST;

Epoller::Epoller():
    epollfd_(epoll_create(kMaxEventLen)),
    events_(kMaxEventLen)
{

}

Epoller::~Epoller()
{
    
}

int Epoller::set_non_blocking(int fd) {
    int old_state = fcntl(fd, F_GETFL);
    int new_state = old_state | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_state);
    return old_state;
}

void Epoller::fill_active_channels(int events_num, ChannelList& channels)
{
    for (int i = 0; i < events_num; i++)
    {
        Channel* channel_ptr = static_cast<Channel*>(events_[i].data.ptr);
        channel_ptr->set_revents(events_[i].events);                        // epoll的类poll处理
        printf("Epoller:: new channel: %d\n", channel_ptr->fd());
        channels.emplace_back(channel_ptr);
    }
}

void Epoller::poll(ChannelList& active_channels)
{
    // printf("epoll start\n");
    int num = epoll_wait(epollfd_, &*events_.begin(), kMaxEventLen, 0);
    fill_active_channels(num, active_channels);
    // printf("epoll: active_channel count: %d\n", active_channels.size());
    // printf("epoll end\n");
}

void Epoller::update(int operation, Channel& channel)
{
    struct epoll_event event;
    memset(&event, 0, sizeof event);
    event.events = channel.events() | EPOLLET;
    event.data.ptr = static_cast<void*>(&channel);

    epoll_ctl(epollfd_, operation, channel.fd(), &event);
}

void Epoller::update_channel(Channel& channel)
{
    int op = 0, events = channel.events();
    Channel::ChannelState state = channel.state();
    if ( state == Channel::ChannelState::kNew || state == Channel::ChannelState::kDelete )
    {
        channel.set_state(Channel::ChannelState::kAdd);
        if (events & EPOLLIN) {
            op = EPOLL_CTL_ADD;
            set_non_blocking(channel.fd());
        }
        else if (events & EPOLLRDHUP)
            op = EPOLL_CTL_DEL;
        else {

        }
    }

    update(op, channel);
}


#endif
