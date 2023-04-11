/*
 * @Author: HH
 * @Date: 2023-04-08 22:26:53
 * @LastEditTime: 2023-04-09 20:36:42
 * @LastEditors: HH
 * @Description: HTTP response，负责将一个完整的HTTP相应写入buff
 * @FilePath: /WebREST/WebREST/core/http_response.h
 */
#ifndef WebREST_HTTP_RESPONSE_H_
#define WebREST_HTTP_RESPONSE_H_

#include "copyable.h"
#include "util.h"

#include <string>
#include <unordered_map>
#include <string_view>

namespace WebREST {

class Buffer;

class HttpResponse: public Copyable {
public:
    enum HttpStatusCode{
        kUnKnown,
        k100Continue = 100,
        k200OK = 200,
        k400BadRequest = 400,
        k403Forbidden = 403,
        k404NotFound = 404,
        k500InternalServerErrno = 500
    };
    HttpResponse(bool close): close_connection_(close){};
    
    void set_status_code(HttpStatusCode code)
    { status_code_ = code; }

    void set_status_message(std::string_view msg)
    { status_msg_ = msg; }

    void setContentType(std::string_view content_type)
    { headers_["Content-Type"] = content_type; }

    void add_header(std::string_view key, std::string_view value)
    { headers_[std::string(key)] = value; }

    void set_body(std::string_view body)
    { body_ = body; }

    void set_close_connection(bool close) 
    { close_connection_ = close; }

    bool close_connection() const
    { return close_connection_; }

    // 按照HTTP Response的格式插入buffer
    void append_to_buffer(Buffer* buf) const;

private:
    static const std::string server_name_;
    static const std::string server_http_version_;
    HttpStatusCode status_code_;
    std::string status_msg_;
    std::unordered_map<std::string, std::string> headers_;
    std::string body_;

    bool close_connection_;
};

} // namespace WebREST

#endif