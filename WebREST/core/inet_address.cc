/*
 * @Author: HH
 * @Date: 2023-04-01 23:14:37
 * @LastEditTime: 2023-04-02 19:40:41
 * @LastEditors: HH
 * @Description: sockaddr_in的封装
 * @FilePath: /WebREST/WebREST/core/inet_address.cc
 */

#ifndef WebREST_INET_ADDRESS_CC_
#define WebREST_INET_ADDRESS_CC_

#include "inet_address.h"

using namespace WebREST;

InetAddress::InetAddress(const char* ip, int port)
{
    memset( &addr_, 0, sizeof addr_ );
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons( port );
    ::inet_pton( AF_INET, ip, &addr_.sin_addr );
}

std::string InetAddress::to_ip() const
{
    char buf[INET_ADDRSTRLEN];
    ::inet_ntop(AF_INET, &addr_.sin_addr, buf, INET_ADDRSTRLEN);
    std::string res(buf);
    return res;
}

std::string InetAddress::to_ip_port() const
{
    std::string res = to_ip();
    unsigned short int hs_port = ::ntohs(addr_.sin_port);
    res += ":" + std::to_string(hs_port);
    return res;
}

#endif