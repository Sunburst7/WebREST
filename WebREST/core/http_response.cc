/*
 * @Author: HH
 * @Date: 2023-04-08 22:57:03
 * @LastEditTime: 2023-04-13 02:53:30
 * @LastEditors: sunburst7 1064658281@qq.com
 * @Description: 
 * @FilePath: /Enhance_Tiny_muduo/WebREST/core/http_response.cc
 */
#ifndef WebREST_HTTP_RESPONSE_CC_
#define WebREST_HTTP_RESPONSE_CC_

#include "http_response.h"
#include "buffer.h"

using namespace WebREST;

const std::string HttpResponse::server_name_ = "WebREST";
const std::string HttpResponse::server_http_version_ = "HTTP/1.1";

void HttpResponse::append_to_buffer(Buffer* buffer) const
{
    char buf[32]{0};
    std::string CRLF = "\r\n";
    snprintf(buf, sizeof buf, "HTTP/1.1 %d", status_code_);
    buffer->append(buf);
    buffer->append(status_msg_);
    buffer->append(CRLF);
    
    if (close_connection_)
        buffer->append("Connection: close\r\n");
    else
    {
        snprintf(buf, sizeof(buf), "Content-Length: %zd\r\n", body_.size()); // no need to memset this is longer than HTTP... one
        buffer->append(buf);
        buffer->append("Connection: Keep-Alive\r\n");
        auto type_header = headers_.find("Content-Type");
        if (type_header != headers_.end())
        {
            buffer->append("Content-Type: ");
            buffer->append(type_header->second);
            buffer->append(CRLF);
        }
        for (const auto& header : headers_)
        {
            buffer->append(header.first);
            buffer->append(": ");
            buffer->append(header.second);
            buffer->append(CRLF);
        }
        buffer->append("Server: ");
        buffer->append(server_name_);
        buffer->append(CRLF);
    }
    buffer->append(CRLF);
    buffer->append(body_);
    return;
}
// void HttpResponse::append_to_buffer(Buffer* buf) const
// {
//     std::string msg = "";
//     std::string CRLF = "\r\n";
//     msg += server_http_version_ + " " + std::to_string(status_code_) + " " + status_msg_ +  CRLF;
    
//     if (close_connection_)
//         msg += "Connection: close" + CRLF;
//     else
//     {
//         msg += "Content-Length: " + std::to_string(body_.size()) + CRLF;
//         msg += "Connection: Keep-Alive" + CRLF;

//         auto type_header = headers_.find("Content-Type");
//         if (type_header != headers_.end())
//             msg += "Content-Type: " + type_header->second + CRLF;
    
//         for (const auto& header : headers_)
//         {
//             msg += header.first;
//             msg += ": ";
//             msg += header.second;
//             msg += CRLF;
//         }
//         msg += "Server: " + server_name_ + CRLF;
//     }
//     msg += CRLF;
//     msg += body_;
//     buf->append(msg);
//     return;
// }

#endif
