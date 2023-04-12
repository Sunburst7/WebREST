/*
 * @Author: HH
 * @Date: 2023-03-31 01:52:54
 * @LastEditTime: 2023-04-11 23:21:06
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
#include "buffer.h"

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

    void onConnection(const TcpConnectionPtr& conn)
    {
        printf("EchoServer - %s -> %s\n", 
            conn->peer_address().to_ip_port().c_str(),
            conn->local_address().to_ip_port().c_str());
    }

    void onMessage(const TcpConnectionPtr& conn, Buffer* buf)
    {
        std::string msg(buf->retrieve_all_as_string());
        printf("echo %d bytes: %s\n", msg.size(), msg.c_str());
        conn->send(msg);
    }
};

} // namespace WebREST

#endif 