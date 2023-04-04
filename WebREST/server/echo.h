/*
 * @Author: HH
 * @Date: 2023-03-31 01:52:54
 * @LastEditTime: 2023-04-04 01:01:23
 * @LastEditors: HH
 * @Description: echo server
 * @FilePath: /WebREST/WebREST/server/echo.h
 */

#ifndef WebREST_ECHO_H_
#define WebREST_ECHO_H_

#include <string>

#include "eventloop.h"
#include "inet_address.h"
#include "tcp_server.h"
#include "tcp_connection.h"

namespace WebREST {

class EchoServer{
public:
    EchoServer(EventLoop* loop, const InetAddress& listen_addr);

    void start() { tcp_server_.start(); }

private:
    EventLoop* loop_;
    TcpServer tcp_server_;
    
    // // 用户自定义
    // void onConnection(const TcpConnectionPtr& conn)
    // {
    //     printf("EchoServer - %s -> %s\n", 
    //         conn->peer_address().to_ip_port().c_str(),
    //         conn->local_address().to_ip_port().c_str());
    // }

    // // 用户自定义
    // void onMessage(const TcpConnectionPtr& conn)
    // {
    //     std::string msg(conn->get());
    //     printf("echo %d bytes: %s\n", msg.size(), msg.c_str());
    //     conn->send(msg);
    // }
        // 用户自定义
    void onConnection(TcpConnection* conn)
    {
        printf("EchoServer - %s -> %s\n", 
            conn->peer_address().to_ip_port().c_str(),
            conn->local_address().to_ip_port().c_str());
    }

    // 用户自定义
    void onMessage(TcpConnection* conn)
    {
        std::string msg(conn->get());
        printf("echo %d bytes: %s\n", msg.size(), msg.c_str());
        conn->send(msg);
    }
};

} // namespace WebREST

#endif 