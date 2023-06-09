/*
 * @Author: HH
 * @Date: 2023-04-01 18:27:11
 * @LastEditTime: 2023-04-14 21:57:29
 * @LastEditors: sunburst7 1064658281@qq.com
 * @Description: 
 * @FilePath: /WebREST/WebREST/core/epoller.cc
 */

#ifndef WebREST_EPOLLER_CC_
#define WebREST_EPOLLER_CC_

#include "epoller.h"
#include "channel.h"
#include "socket.h"

using namespace WebREST;

Epoller::Epoller():
    epollfd_(::epoll_create1(EPOLL_CLOEXEC)),
    events_(kMaxEventLen),
    channels_()
{

}

Epoller::~Epoller()
{
    Socket::close(epollfd_);
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
#ifdef DEBUG_OUTPUT
        printf("[DEBUG] Epoller::fill_active_channel new channel: %d\n", channel_ptr->fd());
#endif
        channels.emplace_back(channel_ptr);
    }
    // if (events_num == static_cast<int>(events_.size()))
    // {
    //     printf("[DEBUG] Epoller::fill_active_channels resize events\n");
    //     events_.resize(events_num * 2);  
    // }

}

void Epoller::poll(ChannelList& active_channels)
{
    // printf("epoll start\n");
    int num = epoll_wait(epollfd_, &*events_.begin(), kMaxEventLen, -1);
    fill_active_channels(num, active_channels);
    // printf("epoll: active_channel count: %d\n", active_channels.size());
    // printf("epoll end\n");
}

void Epoller::update(int operation, Channel& channel)
{
    struct epoll_event event;
    memset(&event, 0, sizeof event);
    event.events = channel.events();    // LT 模式
    event.data.ptr = static_cast<void*>(&channel);

    epoll_ctl(epollfd_, operation, channel.fd(), &event);
}

void Epoller::update_channel(Channel& channel)
{
    int op = 0, events = channel.events();
    int fd = channel.fd();
    Channel::ChannelState state = channel.state();

    if ( state == Channel::ChannelState::kNew || state == Channel::ChannelState::kDeleted )
    {
        if (state == Channel::ChannelState::kNew)
        {
            assert(channels_.find(fd) == channels_.end());
            channels_[fd] = &channel; // 插入到Channel_Map中
        }
        else    // kDeleted
        {
            assert(channels_.find(fd) != channels_.end());
            assert(channels_[fd] == &channel);
        }
        op = EPOLL_CTL_ADD;
        channel.set_state(Channel::ChannelState::kAdded);
    }
    else    // kAdded
    {
        assert(channels_.find(fd) != channels_.end());
        assert(channels_[fd] == &channel);
        if (events == 0) {
            op = EPOLL_CTL_DEL;
            channel.set_state(Channel::ChannelState::kDeleted);
        }
        else 
        {
            op = EPOLL_CTL_MOD;
        }
    }

    update(op, channel);
}

void Epoller::remove_channel(Channel& channel)
{
    int fd = channel.fd();
    Channel::ChannelState state = channel.state();
    // assert(channels_.find(fd) != channels_.end());
    // assert(channels_[fd] == &channel);
    assert(state == Channel::ChannelState::kAdded || state == Channel::ChannelState::kDeleted);

    // channel状态表示没有删除
    if (state == Channel::ChannelState::kAdded)
        update(EPOLL_CTL_DEL, channel);
    channel.set_state(Channel::ChannelState::kNew);
    channels_.erase(fd);
}


#endif
