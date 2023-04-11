/*
 * @Author: HH
 * @Date: 2023-04-08 22:57:03
 * @LastEditTime: 2023-04-10 05:35:08
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/WebREST/core/http_response.cc
 */
#ifndef WebREST_HTTP_RESPONSE_CC_
#define WebREST_HTTP_RESPONSE_CC_

#include "http_response.h"
#include "buffer.h"

using namespace WebREST;

const std::string HttpResponse::server_name_ = "WebREST";
const std::string HttpResponse::server_http_version_ = "HTTP/1.1";

void HttpResponse::append_to_buffer(Buffer* buf) const
{
    std::string msg = "";
    std::string CRLF = "\r\n";
    msg += server_http_version_ + " " + std::to_string(status_code_) + " " + status_msg_ +  CRLF;
    
    if (close_connection_)
        msg += "Connection: close" + CRLF;
    else
    {
        msg += "Content-Length: " + std::to_string(body_.size()) + CRLF;
        msg += "Connection: Keep-Alive" + CRLF;

        auto type_header = headers_.find("Content-Type");
        if (type_header != headers_.end())
            msg += "Content-Type: " + type_header->second + CRLF;
    
        for (const auto& header : headers_)
        {
            msg += header.first;
            msg += ": ";
            msg += header.second;
            msg += CRLF;
        }
        msg += "Server: " + server_name_ + CRLF;
    }
    msg += CRLF;
    msg += body_;
    buf->append(msg);
    return;
}

#endif
