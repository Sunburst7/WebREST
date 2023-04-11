/*
 * @Author: HH
 * @Date: 2023-04-08 23:24:08
 * @LastEditTime: 2023-04-09 20:49:55
 * @LastEditors: HH
 * @Description: HTTP服务器，提供RESTful方法
 * @FilePath: /WebREST/WebREST/server/http.h
 */
#ifndef WebREST_HTTP_H_
#define WebREST_HTTP_H_

#include "eventloop.h"
#include "inet_address.h"
#include "tcp_server.h"
#include "buffer.h"
#include "http_request.h"
#include "http_response.h"

#include <functional>
#include <unordered_map>

namespace WebREST {

class HttpServer {
public:
    using RouterHandler = std::function<void(const HttpRequest& req, HttpResponse& resp)>;
    HttpServer(EventLoop* loop, const InetAddress& address);
    ~HttpServer();

    void start() { server_.start(); }

    void setThreadNum(int numThreads)
    {
        server_.set_thread_num(numThreads);
    }

    // RESTful API
    void Get(const std::string& path, RouterHandler& handler)
    { router_map_["GET"][path] = handler; }
    void Get(const std::string& path, RouterHandler handler)
    { router_map_["GET"][path] = handler; }
    
    void Post(const std::string& path, RouterHandler& handler)
    { router_map_["POST"][path] = handler; }
    void Put(const std::string& path, RouterHandler& handler)
    { router_map_["PUT"][path] = handler; }
    void Delete(const std::string& path, RouterHandler& handler)
    { router_map_["DELETE"][path] = handler; }

private:
    void onConnection(TcpConnection* conn);
    void onMessage(TcpConnection* conn, Buffer* buf);
    void onRequest(TcpConnection* conn, const HttpRequest& request);

    EventLoop* loop_;
    TcpServer server_;
    std::unordered_map<std::string, std::unordered_map<std::string, RouterHandler>> router_map_;
    // std::unordered_map<std::string, RouterHandler> get_router_map_;
    // std::unordered_map<std::string, RouterHandler> post_router_map_;
    // std::unordered_map<std::string, RouterHandler> put_router_map_;
    // std::unordered_map<std::string, RouterHandler> delete_router_map_;

};

} // namespace WebREST

#endif