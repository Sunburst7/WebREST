/*
 * @Author: HH
 * @Date: 2023-03-31 23:01:28
 * @LastEditTime: 2023-04-13 01:27:30
 * @LastEditors: sunburst7 1064658281@qq.com
 * @Description: 可以理解为对某个fd的所有事件的一个管理
 *  每个Channel对象都只属于某一个IO线程。每个Channel对象自始至终只负责一个文件描述符（fd）的IO事件分发
 * @FilePath: /Enhance_Tiny_muduo/WebREST/core/channel.h
 */
#ifndef WebREST_CHANNEL_H_
#define WebREST_CHANNEL_H_

#include <sys/epoll.h>

#include "non_copyable.h"
#include "callback.h"

namespace WebREST {
    
class EventLoop;

class Channel : NonCopyable{
public:
    enum ChannelState{  // 表示在Epoller.channelmap内的状态(与内核事件表同步)
        kNew = -1,      // 新channel， 没有添加到map
        kAdded = 1,     // 已插入map
        kDeleted = 2,   // 已从map删除
    };
    Channel(EventLoop* loop, int fd);
    ~Channel();

    void handle_event();

    void set_read_callback(const EventCallback& cb) { read_cb_ = std::move(cb); }
    void set_write_callback(const EventCallback& cb) { write_cb_ = std::move(cb); }
    void set_close_callback(const EventCallback& cb) { close_cb_ = std::move(cb); }
    // rvalue
    void set_read_callback(const EventCallback&& cb) { read_cb_ = cb; }
    void set_write_callback(const EventCallback&& cb) { write_cb_ = cb; }
    void set_close_callback(const EventCallback&& cb) { close_cb_ = cb; }

    void update();
    void remove();
    
    void enable_reading() { events_ |= EPOLLIN; update(); }
    void enable_writing() { events_ |= EPOLLOUT; update(); } 
    void disable_writing() { events_ &= ~EPOLLOUT; update(); }
    void disbale_all() { events_ = 0; update(); }
    
    bool is_reading() const { return events_ & EPOLLIN; }
    bool is_writing() const { return events_ & EPOLLOUT; }
    
    int fd() const { return fd_; }
    int events() const { return events_; }
    
    int revents() const { return revents_; }
    void set_revents(int e) { revents_ = e; }

    ChannelState state() const { return state_; }
    void set_state(ChannelState state) { state_ = state; }

private:
    EventLoop* loop_;
    int fd_;
    int events_;
    int revents_;

    ChannelState state_;
    EventCallback read_cb_;
    EventCallback write_cb_;
    EventCallback close_cb_;
};

} // namespace WebREST

#endif