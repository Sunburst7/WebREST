/*
 * @Author: HH
 * @Date: 2023-04-02 01:47:10
 * @LastEditTime: 2023-04-03 20:09:20
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/WebREST/core/acceptor.cc
 */

#ifndef WebREST_ACCEPT_CC_
#define WebREST_ACCEPT_CC_

#include "acceptor.h"
#include "eventloop.h"

using namespace WebREST;

Acceptor::Acceptor(EventLoop* loop, const InetAddress& listen_addr):
    loop_(loop),
    accept_sock_(Socket::CreateNonBlockingFD()),
    accept_channel_(loop, accept_sock_.fd())
{
    accept_sock_.bind(listen_addr);
    accept_channel_.set_read_callback(
        // 指向成员变量的函数需要加取地址符
        std::bind(&Acceptor::handle_new_connection, this)
    );
}

void Acceptor::listen()
{
    accept_sock_.listen();
    accept_channel_.enable_reading();
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
    int connfd = accept_sock_.accpet(peer_addr);    // assert connfd >= 0
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