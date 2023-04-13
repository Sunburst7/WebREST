/*
 * @Author: HH
 * @Date: 2023-04-02 00:18:16
 * @LastEditTime: 2023-04-13 00:00:05
 * @LastEditors: sunburst7 1064658281@qq.com
 * @Description: 对linux socket api的封装，生命周期是整个socket存在周期
 * @FilePath: /Enhance_Tiny_muduo/WebREST/core/socket.h
 */

#ifndef WebREST_SOCKET_H_
#define WebREST_SOCKET_H_

#include <sys/socket.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <netinet/tcp.h>

#include "non_copyable.h"

namespace WebREST {

class InetAddress;

class Socket : NonCopyable {
public:
    // socketfd的工厂函数
    static int CreateNonBlockingFD();

    // 获取某个socketfd的InetAddress
    static InetAddress get_local_addr(int sockfd);
    
    explicit Socket(int sockfd): sockfd_(sockfd) {};
    ~Socket() { close(sockfd_); }

    int fd() const { return sockfd_; }

    void bind(const InetAddress&);
    void listen();
    int accept(InetAddress&);
    int accept(InetAddress&, int flag);
    static int close(int sockfd);
    int close();
    void shutdown_write();
    
    void set_sock_opt(int opt_name, int opt_val);
    void set_tcp_no_delay(bool on);
private:
    const int sockfd_;
};

} // namespace WebREST

#endif
