/*
 * @Author: HH
 * @Date: 2023-04-02 18:41:29
 * @LastEditTime: 2023-04-12 23:00:14
 * @LastEditors: sunburst7 1064658281@qq.com
 * @Description: 
 * @FilePath: /Enhance_Tiny_muduo/WebREST/core/tcp_server.cc
 */

#ifndef WebREST_TCP_SERVER_CC_
#define WebREST_TCP_SERVER_CC_

#include "tcp_server.h"
#include "eventloop.h"
#include "acceptor.h"
#include "eventloop_thread_pool.h"


using namespace WebREST;

// 框架内默认connection_callback与messaeg_callback
void default_connection_callback(const TcpConnectionPtr& conn)
{
    printf("%s -> %s connected\n", 
        conn->local_address().to_ip_port().c_str(),
        conn->peer_address().to_ip_port().c_str());
}
void default_message_callback(const TcpConnectionPtr& conn, Buffer* buf)
{
    printf("%s\n", buf->retrieve_all_as_string().c_str());
}

TcpServer::TcpServer(EventLoop* loop, const InetAddress& listen_addr):
    loop_(loop),
    listen_addr_(listen_addr),
    acceptor_(new Acceptor(loop, listen_addr)),
    thread_pool_(new EventLoopThreadPool(loop_)),
    connection_callback_(default_connection_callback),
    message_callback_(default_message_callback)
{
    acceptor_->setNewConnectionCallback(
        std::bind(&TcpServer::new_connection, this, _1, _2)
    );
}

TcpServer::~TcpServer()
{
    for (auto& pair: connections_)
    {
        TcpConnectionPtr ptr(pair.second);
        pair.second.reset();                // 重置计数销毁TcpConnection
        ptr->loop()->run_in_loop(
            std::bind(&TcpConnection::connection_destroyed, ptr)
        );
    }
}

void TcpServer::set_thread_num(int num)
{
    assert(num >= 0);
    thread_pool_->set_thread_num(num);
}

void TcpServer::new_connection(int connfd, const InetAddress& peer_addr)
{
    printf("[DEBUG] TcpServer::new_connection new connection coming, socket_fd:%d address: %s\n", connfd, peer_addr.to_ip_port().c_str());
    EventLoop* io_loop = thread_pool_->get_next_loop();
    TcpConnectionPtr conn = std::make_shared<TcpConnection>(        
        loop_, 
        connfd,
        listen_addr_,
        peer_addr
    );
    connections_[connfd] = conn;
    printf("[DEBUG] TcpServer::new_connection current connection num: %d\n", connections_.size());
    conn->set_connection_callback(connection_callback_);
    conn->set_message_callback(message_callback_);
    conn->set_close_callback(std::bind(&TcpServer::remove_connection, this, _1));
    loop_->run_in_loop(std::bind(&TcpConnection::connection_established, conn));
}

void TcpServer::remove_connection_in_loop(const TcpConnectionPtr& ptr)
{
    assert(connections_.find(ptr->fd()) != connections_.end());
    connections_.erase(connections_.find(ptr->fd()));
    EventLoop* io_loop = ptr->loop();
    io_loop->run_in_loop(std::bind(&TcpConnection::connection_destroyed, ptr)); // 在IO loop中执行destroy
}

void TcpServer::remove_connection(const TcpConnectionPtr& ptr)
{
    loop_->run_in_loop(std::bind(&TcpServer::remove_connection_in_loop, this, ptr));
}

void TcpServer::start()
{
    thread_pool_->start();
    loop_->run_in_loop(std::bind(&Acceptor::listen, acceptor_.get()));
}



#endif
