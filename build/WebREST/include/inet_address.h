/*
 * @Author: HH
 * @Date: 2023-04-01 23:14:30
 * @LastEditTime: 2023-04-04 04:58:15
 * @LastEditors: HH
 * @Description: 对sockaddr的封装，提供了一系列转换函数
 * @FilePath: /WebREST/WebREST/core/inet_address.h
 */

//     /* Structure describing an Internet socket address.  */
//     struct sockaddr_in {
//         sa_family_t    sin_family; /* address family: AF_INET */
//         uint16_t       sin_port;   /* port in network byte order */
//         struct in_addr sin_addr;   /* internet address */
//     };

//     /* Internet address. */
//     typedef uint32_t in_addr_t;
//     struct in_addr {
//         in_addr_t       s_addr;     /* address in network byte order */
//     };

//     struct sockaddr_in6 {
//         sa_family_t     sin6_family;   /* address family: AF_INET6 */
//         uint16_t        sin6_port;     /* port in network byte order */
//         uint32_t        sin6_flowinfo; /* IPv6 flow information */
//         struct in6_addr sin6_addr;     /* IPv6 address */
//         uint32_t        sin6_scope_id; /* IPv6 scope-id */
//     };

#ifndef WebREST_INET_ADDRESS_H_
#define WebREST_INET_ADDRESS_H_

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <cstring>
#include <stdlib.h>
#include <string>

#include "copyable.h"

namespace WebREST {

class InetAddress : Copyable{
public:
    InetAddress(sockaddr_in addr): addr_(addr){};
    InetAddress(const char* ip, int port);
    InetAddress(const char* ip, const char* port): InetAddress(ip, atoi(port)){};
    InetAddress(int port): InetAddress("127.0.0.1", port){};
    InetAddress(const char* port): InetAddress("127.0.0.1", port){};
    InetAddress(): InetAddress(0){};

    // getter
    sa_family_t family() const { return addr_.sin_family; }
    uint16_t port() const { return addr_.sin_port; }
    struct sockaddr* sock_addr() const { return (struct sockaddr*)(&addr_); } // not const
    
    // util
    socklen_t len() const { return sizeof(addr_); }
    std::string to_ip() const;
    std::string to_ip_port() const;

private:
    union
    {
        struct sockaddr_in addr_;
    };
};

} // namespace WebREST

#endif