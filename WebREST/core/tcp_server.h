/*
 * @Author: HH
 * @Date: 2023-04-02 18:41:22
 * @LastEditTime: 2023-04-03 23:35:20
 * @LastEditors: HH
 * @Description: TCP 服务器类
 * @FilePath: /WebREST/WebREST/core/tcp_server.h
 */

#ifndef WebREST_TCP_SERVER_H_
#define WebREST_TCP_SERVER_H_

#include <memory>

#include "non_copyable.h"
#include "tcp_connection.h"
#include "callback.h"
#include "inet_address.h"

namespace WebREST {

class Acceptor;
class EventLoop;

class TcpServer : NonCopyable{
public:
    TcpServer(EventLoop* loop, const InetAddress& listen_addr);
    ~TcpServer();

    void start();

    void set_connection_callback(const ConnectionCallback& cb)
    { connection_callback_ = cb; }

    void set_message_callback(const MessageCallback& cb)
    { message_callback_ = cb; }

private:
    // 框架定义的Acceptor的NewConnectionCallback
    // sockfd是local socket
    void new_connection(int sockfd, const InetAddress& peer_addr);
    
    // 当前server所处的ip和port
    const InetAddress listen_addr_;
    EventLoop* loop_;
    std::unique_ptr<Acceptor> acceptor_;

    // user设置，但最后会绑在TcpConnection中
    ConnectionCallback connection_callback_;
    MessageCallback message_callback_;
};
} // namespace WebREST

#endif