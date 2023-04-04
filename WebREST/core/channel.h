/*
 * @Author: HH
 * @Date: 2023-03-31 23:01:28
 * @LastEditTime: 2023-04-03 19:11:32
 * @LastEditors: HH
 * @Description: 可以理解为对某个fd的所有事件的一个管理
 *  每个Channel对象都只属于某一个IO线程。每个Channel对象自始至终只负责一个文件描述符（fd）的IO事件分发
 * @FilePath: /WebREST/WebREST/core/channel.h
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
    Channel(EventLoop* loop, int fd);
    ~Channel();

    void handle_event();

    void set_read_callback(const EventCallback& cb) { read_cb_ = cb; }
    void set_write_callback(const EventCallback& cb) { write_cb_ = cb; }

    void update();
    
    void enable_reading() {
        events_ |= EPOLLIN;
        update();
    }

    void enable_writing() {
        events_ |= EPOLLOUT;
        update();
    } 

    int fd() { return fd_; }
    int events() { return events_; }
    int revents() { return revents_; }
    void set_revents(int e) { revents_ = e; }

private:
    EventLoop* loop_;
    int fd_;
    int events_;
    int revents_;

    EventCallback read_cb_;
    EventCallback write_cb_;
};

} // namespace WebREST

#endif