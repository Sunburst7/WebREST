/*
 * @Author: HH
 * @Date: 2023-04-08 23:24:14
 * @LastEditTime: 2023-04-14 03:15:25
 * @LastEditors: sunburst7 1064658281@qq.com
 * @Description: 
 * @FilePath: /WebREST/WebREST/server/http.cc
 */
#ifndef WebREST_HTTP_CC_
#define WebREST_HTTP_CC_

#include "http.h"

using namespace WebREST;

void defaultHttpCallback(const HttpRequest&, HttpResponse* resp)
{
  resp->set_status_code(HttpResponse::k404NotFound);
  resp->set_status_message("Not Found");
  resp->set_close_connection(true);
}

HttpServer::HttpServer(EventLoop* loop, const InetAddress& address, bool auto_close_idle_connection):
    loop_(loop), server_(loop, address), auto_close_idle_connection_(auto_close_idle_connection)
{
    server_.set_connection_callback(
        std::bind(&HttpServer::onConnection, this, _1)
    );
    server_.set_message_callback(
        std::bind(&HttpServer::onMessage, this, _1, _2)
    );
    server_.set_thread_num(8);
    router_map_["GET"]      = std::unordered_map<std::string, RouterHandler>();
    router_map_["POST"]     = std::unordered_map<std::string, RouterHandler>();
    router_map_["PUT"]      = std::unordered_map<std::string, RouterHandler>();
    router_map_["DELETE"]   = std::unordered_map<std::string, RouterHandler>();
}

HttpServer::~HttpServer()
{

}

void HttpServer::onIdle(std::weak_ptr<TcpConnection>& connection) {
    TcpConnectionPtr conn(connection.lock());
    if (conn) 
    {
        if (TimeStamp::add_time(conn->last_message(), kConnectionTimeout) < TimeStamp::now()) 
        {
            printf("[DEBUG] %s HttpServer::HandleIdleConnection\n", TimeStamp::now().to_format_string().data()); 
            conn->shutdown();
        } 
        else 
            loop_->run_after(kConnectionTimeout, std::move(std::bind(&HttpServer::onIdle, this, connection))); 
    }
}

void HttpServer::onConnection(const TcpConnectionPtr& conn)
{
    printf("[DEBUG] HttpServer::onConnection new connection come\n");
    // 创建一个每隔kCOnnectionTimeout就检查是否需要关闭连接的定时函数
    if (auto_close_idle_connection_)
    {
        loop_->run_after(kConnectionTimeout, std::move(std::bind(&HttpServer::onIdle, this, std::weak_ptr<TcpConnection>(conn)))); 
    }
}

void HttpServer::onMessage(const TcpConnectionPtr& conn, Buffer* buffer)
{
    // printf("onMessage\n%s\n", buffer->peek_as_string().c_str());
    conn->set_last_message(TimeStamp::now());   // 更新最后一次消息传送的时间
    if (conn->is_shutdown()) return;
    HttpRequest req;
    if (!req.parse(buffer))
    {
        // printf("onMessage: parse err!\n");
        conn->send("HTTP/1.1 400 Bad Request\r\n\r\n");
        conn->shutdown();
    }

    if (req.got_all())
    {
        onRequest(conn, req);
        req.reset();            // 处理长连接
    }
}

void HttpServer::onRequest(const TcpConnectionPtr& conn, const HttpRequest& request)
{
    // printf("onRequest\n");
    std::string connection_state = std::move(request.get_header("Connection"));
    bool close = (connection_state == "Close" || 
        (request.version() == HttpRequest::Version::kHttp10 && connection_state != "keep-alive"));
    HttpResponse response(close); 
    std::string method = request.method_to_string();
    std::string path = request.path();

    printf("[DEBUG] HttpServer::onRequest method: %s, path: %s\n", method.c_str(), path.c_str());

    // 处理路由
    auto method_router_map = router_map_.find(method);
    if ( method_router_map != router_map_.end() )
    {
        auto iter = method_router_map->second.find(path);
        if ( iter != method_router_map->second.end() )
            iter->second(request, response);
        else
        {
            response.set_status_code(HttpResponse::HttpStatusCode::k404NotFound);
            response.set_status_message("Not Found");
            response.set_body("Sorry, Not Found Path: " + path +"\n");
            response.set_close_connection(true);
        }
    }
    else
    {
        response.set_status_code(HttpResponse::HttpStatusCode::k400BadRequest);
        response.set_status_message("Bad Request");
        response.set_body("Sorry! Server Don't Deal With Method: " + method + "\n");
        response.set_close_connection(true);
    }
    

    Buffer buffer;
    response.append_to_buffer(&buffer);
    conn->send(&buffer);
    
    if (response.close_connection()) {
        conn->shutdown();
    } 
}

#endif