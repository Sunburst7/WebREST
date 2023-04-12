/*
 * @Author: HH
 * @Date: 2023-04-02 18:41:22
 * @LastEditTime: 2023-04-11 22:46:21
 * @LastEditors: HH
 * @Description: TCP 服务器类
 * @FilePath: /WebREST/WebREST/core/tcp_server.h
 */

#ifndef WebREST_TCP_SERVER_H_
#define WebREST_TCP_SERVER_H_

#include <assert.h>
#include <memory>
#include <iostream>

#include "non_copyable.h"
#include "tcp_connection.h"
#include "callback.h"
#include "inet_address.h"
#include "buffer.h"

namespace WebREST {

class Acceptor;
class EventLoop;
class EventLoopThreadPool;

class TcpServer : NonCopyable{
public:
    TcpServer(EventLoop* loop, const InetAddress& listen_addr);
    ~TcpServer();

    void start();

    void set_thread_num(int num);

    void set_connection_callback(const ConnectionCallback& cb)
    { connection_callback_ = cb; }

    void set_message_callback(const MessageCallback& cb)
    { message_callback_ = cb; }

private:
    using ConnectionMap = std::unordered_map<int, TcpConnectionPtr>;
    // 框架定义的Acceptor的NewConnectionCallback
    // sockfd是local socket
    void new_connection(int sockfd, const InetAddress& peer_addr);
    // 线程安全的
    void remove_connection(const TcpConnectionPtr& ptr);
    // 非线程安全，但在EventLoop中
    void remove_connection_in_loop(const TcpConnectionPtr& ptr);
    
    // 当前server所处的ip和port
    const InetAddress listen_addr_;
    EventLoop* loop_;
    std::unique_ptr<Acceptor> acceptor_;
    std::shared_ptr<EventLoopThreadPool> thread_pool_;
    ConnectionMap connections_;                 // T目前存活的TcpConnection的shared_ptr
    // user设置，但最后会绑在TcpConnection中
    ConnectionCallback connection_callback_;
    MessageCallback message_callback_;
};
} // namespace WebREST

#endif