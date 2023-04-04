/*
 * @Author: HH
 * @Date: 2023-04-01 18:27:06
 * @LastEditTime: 2023-04-03 05:21:35
 * @LastEditors: HH
 * @Description: epoll系列函数封装，通知channel修改保存的事件
 * @FilePath: /WebREST/WebREST/core/epoller.h
 */

#ifndef WebREST_EPOLLER_H_
#define WebREST_EPOLLER_H_

#include <sys/epoll.h>
#include <fcntl.h>
#include <cstring>
#include <vector>

#include "non_copyable.h"

namespace WebREST {

class Channel;

class Epoller : NonCopyable {

public:
    using EventList = std::vector<epoll_event>;    
    using ChannelList = std::vector<Channel*>;

    Epoller();
    ~Epoller();

    // 调用epoll_wait
    void poll(ChannelList& active_channels);

    // epoller 通过 update 函数与操作内核事件表（调用epoll_ctl）
    // 同时修改channel.fd为ET 
    void update(int operation, Channel& channel);
    // 根据channel注册的event事件操作调用update操作内核事件表
    void update_channel(Channel& channel);
private:
    static const int kMaxEventLen = 8;
    int epollfd_;       // epoll标识符
    EventList events_;  // epoll_wait返回的回调事件

    // 设置fd为非阻塞
    int set_non_blocking(int fd);
    // 将epoll返回的events转换为channel* 插入到channels中
    void fill_active_channels(int events_num, ChannelList& channels);
};

} // namespace WebREST

#endif