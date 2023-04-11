/*
 * @Author: HH
 * @Date: 2023-03-31 18:48:02
 * @LastEditTime: 2023-04-03 05:56:36
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/example/test.cc
 */
#include <iostream>

#include "eventloop.h"
#include "inet_address.h"
#include "echo.h"

using namespace std;
using namespace WebREST;

int main() {
    EventLoop loop;
    InetAddress listen_addr(54321);
    EchoServer server(&loop, listen_addr);
    server.start();
    loop.loop();
}