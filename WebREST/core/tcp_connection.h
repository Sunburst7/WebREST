/*
 * @Author: HH
 * @Date: 2023-04-02 04:05:59
 * @LastEditTime: 2023-04-04 05:01:33
 * @LastEditors: HH
 * @Description: tcp通信一方的功能类，通过它实现读写msg，可以是server或client, 不会给用户曝露细节
 * @FilePath: /WebREST/WebREST/core/tcp_connection.h
 */
#ifndef WebREST_TCP_CONNECTION_H_
#define WebREST_TCP_CONNECTION_H_

#include <string.h>
#include <memory>
#include <string>
#include <string_view>

#include "callback.h"
#include "non_copyable.h"
#include "inet_address.h"


namespace WebREST {

class Channel;
class EventLoop;
class Socket;

class TcpConnection :  NonCopyable {
                    //    public std::enable_shared_from_this<TcpConnection> {
public:
    TcpConnection(EventLoop* loop, 
                  int sockfd,
                  const InetAddress& local_addr,
                  const InetAddress& peer_addr);
    ~TcpConnection(){};
    
    const InetAddress& local_address() const { return local_addr_; }
    const InetAddress& peer_address() const { return peer_addr_; }

    void set_connection_callback(const ConnectionCallback& cb) { 
        connection_callback_ = cb;
    }

    void set_message_callback(const MessageCallback& cb) {
        message_callback_ = cb;
    }

    // called when TcpServer accepts a new connection（调用connection_callback）
    void connection_established();

    void send(std::string_view str);
    std::string get();

    // 处理读
    void handle_read();

private:
    InetAddress local_addr_;
    InetAddress peer_addr_;
    EventLoop* loop_;
    // 已经建立好连接的socket（无论是TcpServer被动接受还是TcpClient主动发起）
    // 作为Tcp client就是client的fd，作为server就是server的fd
    Socket* socket_;    
    Channel* channel_;
    char buf_[1024] = {0};

    ConnectionCallback connection_callback_;
    MessageCallback message_callback_;
};
typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;
} // namespace WebREST

#endif