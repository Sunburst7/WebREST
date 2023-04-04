/*
 * @Author: HH
 * @Date: 2023-03-31 01:40:11
 * @LastEditTime: 2023-04-04 04:56:45
 * @LastEditors: HH
 * @Description: 每个线程的主要事件循环，通过不断调用loop函数实现
 * @FilePath: /WebREST/WebREST/core/eventloop.h
 */

#ifndef WebREST_EVENTLOOP_H_
#define WebREST_EVENTLOOP_H_

#include <functional>
#include <assert.h>
#include <sys/epoll.h>
#include <thread>
#include <vector>

#include "epoller.h"

namespace WebREST {

class Channel;
class Epoller;

class EventLoop : NonCopyable{
public:
    using Func =  std::function<void()>;

    EventLoop();
    ~EventLoop();
    
    // static EventLoop* get_eventloop_of_current_thread();

    void loop();
    void update_channel(Channel& channel) { epoller_->update_channel(channel); };

    void run_in_loop(const Func& cb) { cb(); }
    // void assert_in_loop_thread();
    // bool is_in_loop_thread();

private:
    using ChannelList = std::vector<Channel*>;
    Epoller* epoller_;
    
    ChannelList active_channels_;
    int weakup_fd_;
};


} // namespace WebREST

#endif