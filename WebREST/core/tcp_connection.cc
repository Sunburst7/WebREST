/*
 * @Author: HH
 * @Date: 2023-04-02 04:06:10
 * @LastEditTime: 2023-04-04 00:51:35
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/WebREST/core/tcp_connection.cc
 */

#ifndef WebREST_TCP_CONNECTION_CC_
#define WebREST_TCP_CONNECTION_CC_

#include "tcp_connection.h"
#include "eventloop.h"
#include "channel.h"
#include "socket.h"

using namespace WebREST;

TcpConnection::TcpConnection(EventLoop* loop, 
                             int sockfd,
                             const InetAddress& local_addr,
                             const InetAddress& peer_addr):
    loop_(loop),
    socket_(new Socket(sockfd)),
    channel_(new Channel(loop, sockfd)),
    local_addr_(local_addr),
    peer_addr_(peer_addr)
{
    channel_->set_read_callback(
        std::bind(&TcpConnection::handle_read, this)
    );
}

void TcpConnection::connection_established()
{
    channel_->enable_reading();
    // connection_callback_(shared_from_this());
    connection_callback_(this);
}

void TcpConnection::send(std::string_view str)
{
    strcpy(buf_, str.data());
    ::send(socket_->fd(), (const void*)buf_, sizeof(buf_), 0);
}

std::string TcpConnection::get()
{
    std::string res {buf_};
    memset(buf_, 0, sizeof(buf_));
    return res;
}

void TcpConnection::handle_read()
{
    // read from socketfd
    memset(buf_, 0, sizeof(buf_));
    int num = ::recv(socket_->fd(), (void*)buf_, 1024, 0);
    if (num > 0)
    {
        printf("TcpConnection:: get %d bytes msg: %s\n", num, buf_);
        // message_callback_(shared_from_this());
        message_callback_(this);
    }
}

#endif
