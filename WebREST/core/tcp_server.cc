/*
 * @Author: HH
 * @Date: 2023-04-02 18:41:29
 * @LastEditTime: 2023-04-09 20:37:11
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/WebREST/core/tcp_server.cc
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
    thread_pool_(new EventLoopThreadPool(loop_))
    // connection_callback_(default_connection_callback),
    // message_callback_(default_message_callback)
{
    acceptor_->setNewConnectionCallback(
        std::bind(&TcpServer::new_connection, this, _1, _2)
    );
}

TcpServer::~TcpServer()
{
    
}

void TcpServer::set_thread_num(int num)
{
    assert(num >= 0);
    thread_pool_->set_thread_num(num);
}

void TcpServer::new_connection(int connfd, const InetAddress& peer_addr)
{
    printf("TcpServer:: new connection coming, socket_fd:%d address: %s\n", connfd, peer_addr.to_ip_port().c_str());
    EventLoop* io_loop = thread_pool_->get_next_loop();
    // TcpConnectionPtr conn = std::make_shared<TcpConnection>(        
    //     loop_, 
    //     connfd,
    //     listen_addr_,
    //     peer_addr
    // );
    std::cout << "TcpServer:: thread_id: "<< io_loop->thread_id() << std::endl;
    TcpConnection* conn = new TcpConnection(        
        io_loop, 
        connfd,
        listen_addr_,
        peer_addr
    );
    conn->set_connection_callback(connection_callback_);
    conn->set_message_callback(message_callback_);
    loop_->run_in_loop(std::bind(&TcpConnection::connection_established, conn));
}

void TcpServer::start()
{
    thread_pool_->start();
    loop_->run_in_loop(std::bind(&Acceptor::listen, acceptor_.get()));
}



#endif
