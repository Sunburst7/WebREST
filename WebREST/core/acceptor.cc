/*
 * @Author: HH
 * @Date: 2023-04-02 01:47:10
 * @LastEditTime: 2023-04-13 00:12:09
 * @LastEditors: sunburst7 1064658281@qq.com
 * @Description: 
 * @FilePath: /Enhance_Tiny_muduo/WebREST/core/acceptor.cc
 */

#ifndef WebREST_ACCEPT_CC_
#define WebREST_ACCEPT_CC_

#include "acceptor.h"
#include "eventloop.h"

using namespace WebREST;

Acceptor::Acceptor(EventLoop* loop, const InetAddress& listen_addr):
    idlefd_(::open("/dev/null", O_RDONLY | O_CLOEXEC)),
    loop_(loop),
    accept_sock_(Socket::CreateNonBlockingFD()),
    accept_channel_(new Channel(loop, accept_sock_.fd()))
{
    accept_sock_.set_sock_opt(SO_KEEPALIVE, 1);             // 设置listen_sock启用保活定时器，以及重用time_wait状态下socket
    accept_sock_.set_sock_opt(SO_REUSEADDR, 1);
    accept_sock_.bind(listen_addr);
    accept_channel_->set_read_callback(
        std::bind(&Acceptor::handle_new_connection, this)   // 指向成员变量的函数需要加取地址符
    );
}

Acceptor::~Acceptor()
{
    accept_channel_->disbale_all();
    accept_channel_->remove();
    accept_sock_.close();
}

void Acceptor::listen()
{
    accept_sock_.listen();
    accept_channel_->enable_reading();
}

// Acceptor::handleRead()的策略很简单，每次accept(2)一个socket。另
// 外还有两种实现策略，一是每次循环accept(2)，直至没有新的连接到
// 达；二是每次尝试accept(2)N个新连接，N的值一般是10。后面这两种做
// 法适合短连接服务，而muduo是为长连接服务优化的，因此这里用了最
// 简单的办法。这三种策略的对比见论文《accept()able Strategies for
// Improving Web Server Performance》
void Acceptor::handle_new_connection()
{
    InetAddress peer_addr;
    int connfd = accept_sock_.accept(peer_addr, SOCK_NONBLOCK | SOCK_CLOEXEC);    // assert connfd >= 0
    if (connfd < 0)
    {
        if (errno == EMFILE) // 表示进程打开的文件描述符达到了上限
        {
            Socket::close(idlefd_);
            idlefd_ = ::accept(accept_sock_.fd(), NULL, NULL);
            Socket::close(idlefd_);
            idlefd_ = ::open("/dev/null", O_RDONLY | O_CLOEXEC);
        }
        return;
    }
    int val = 1;
    ::setsockopt(connfd, SOL_SOCKET, SO_KEEPALIVE, &val, static_cast<socklen_t>(sizeof val));
    ::setsockopt(connfd, IPPROTO_TCP, TCP_NODELAY, &val, static_cast<socklen_t>(sizeof val));
    if (new_connection_cb_)
    {
        new_connection_cb_(connfd, peer_addr);
    }
    else
    {
        Socket::close(connfd);
    }
}


#endif