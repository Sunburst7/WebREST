/*
 * @Author: HH
 * @Date: 2023-04-02 01:47:04
 * @LastEditTime: 2023-04-12 23:19:05
 * @LastEditors: sunburst7 1064658281@qq.com
 * @Description: 通过Socket监听并接受新连接，调用内核NewConnectionCallback
 * @FilePath: /Enhance_Tiny_muduo/WebREST/core/acceptor.h
 */

#ifndef WebREST_ACCPETOR_H_
#define WebREST_ACCEPTOR_H_

#include "channel.h"
#include "socket.h"
#include "non_copyable.h"
#include "callback.h"

namespace WebREST {

class EventLoop;
class InetAddress;

class Acceptor : NonCopyable {
public:
    // 有新连接建立的事件回调——使用者不可见
    using NewConnectionCallback = std::function<void (int sockfd, const InetAddress&)>;
    
    Acceptor(EventLoop* loop, const InetAddress& listen_addr);
    ~Acceptor();

    void setNewConnectionCallback(const NewConnectionCallback& cb)
    { new_connection_cb_ = cb; }
    
    void listen();

private:
    // 新连接建立的回调函数，会注册在accept_channel的read_cd_中
    void handle_new_connection();

    EventLoop* loop_;
    Socket accept_sock_;
    std::unique_ptr<Channel> accept_channel_;
    NewConnectionCallback new_connection_cb_;
};
} // namespace WebREST

#endif