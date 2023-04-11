/*
 * @Author: HH
 * @Date: 2023-04-02 04:06:10
 * @LastEditTime: 2023-04-10 05:38:19
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
    shutdown_(false),
    loop_(loop),
    socket_(new Socket(sockfd)),
    channel_(new Channel(loop, sockfd)),
    local_addr_(local_addr),
    peer_addr_(peer_addr)
{
    channel_->set_read_callback(
        std::bind(&TcpConnection::handle_read, this)
    );
    channel_->set_write_callback(
        std::bind(&TcpConnection::handle_write, this)
    );
}

void TcpConnection::connection_established()
{
    channel_->enable_reading();
    // connection_callback_(shared_from_this());
    connection_callback_(this);
}

void TcpConnection::shutdown() {
    if (!channel_->is_writing())
    {
        shutdown_ = true;
        socket_->shutdown_write();
    }
}

void TcpConnection::handle_read()
{
    // read from socketfd
    int err_num = 0;
    int num = input_buf_.read_fd(socket_->fd(), err_num);
    if (num > 0)
    {
        printf("TcpConnection:: get %d bytes\n", num);
        // message_callback_(shared_from_this());
        message_callback_(this, &input_buf_);
    }
}

void TcpConnection::handle_write()
{
    if (channel_->is_writing())
    {
        int n = ::send(socket_->fd(), output_buf_.begin_read(), output_buf_.readable_bytes(), 0);
        if ( n > 0 )
        {
            output_buf_.retrieve(n);
            if (output_buf_.readable_bytes() == 0)
            {
                channel_->disable_writing();
            }
        }
        else
        {
            printf("TcpConnection:: handle_write");
        }
    }
    else
    {
        printf("TcpCOnnection:: connection fd = %d is down, no more writing", socket_->fd());
    }
}

void TcpConnection::send(const char* msg, int len)
{
    int remaining = len;
    int send_size = 0;
    // if no thing in output queue, try writing directly
    if (!channel_->is_writing() && output_buf_.readable_bytes() == 0)
    {
        send_size = ::send(socket_->fd(), msg, len, 0);
        remaining -= send_size;
    }

    assert(remaining <= len);
    // 如果没有发送完全，将剩余的内容添加到buf中下次发送
    if (remaining > 0)
    {
        output_buf_.append(msg + send_size, remaining);
        if (!channel_->is_writing())
            channel_->enable_writing();
    }
}

void TcpConnection::send(std::string_view msg)
{
    send(msg.data(), msg.size());
}

void TcpConnection::send(Buffer* buf)
{
    send(buf->begin_read(), buf->readable_bytes());
}

#endif
