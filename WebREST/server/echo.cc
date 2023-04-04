/*
 * @Author: HH
 * @Date: 2023-04-03 06:07:15
 * @LastEditTime: 2023-04-03 20:04:48
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/WebREST/server/echo.cc
 */
#ifndef WebREST_ECHO_CC_
#define WebREST_ECHO_CC_

#include "echo.h"

using namespace WebREST;

EchoServer::EchoServer(EventLoop* loop, const InetAddress& listen_addr):
    loop_(loop),
    tcp_server_(loop, listen_addr)
{
    tcp_server_.set_connection_callback(std::bind(&EchoServer::onConnection, this, _1));
    tcp_server_.set_message_callback(std::bind(&EchoServer::onMessage, this, _1));
}

#endif
