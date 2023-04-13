/*
 * @Author: HH
 * @Date: 2023-04-07 22:40:22
 * @LastEditTime: 2023-04-13 00:32:43
 * @LastEditors: sunburst7 1064658281@qq.com
 * @Description: 表示一个HTTP请求
 * @FilePath: /Enhance_Tiny_muduo/WebREST/core/http_request.h
 */

// GET / HTTP/1.1               --request line(method path+query version)
// Host: developer.mozilla.org  --header
// Accept-Language: fr
//
// name=xxx&age=14              --body


#ifndef WebREST_HTTP_REQUEST_H_
#define WebREST_HTTP_REQUEST_H_

#include <iostream>
#include <unordered_map>
#include <string>
#include <string_view>
#include <algorithm>

#include "copyable.h"

namespace WebREST {

class Buffer;

class HttpRequest: public Copyable {
public:
    enum Method
    {
        kInvalid, kGet, kPost, kPut, kDeleted, kOptions,
    };
    enum Version
    {
        kUnknown, kHttp10, kHttp11
    };
    enum HttpRequestState
    {
        kExpectRequestLine,
        kExpectHeaders,
        kExpectBody,
        kGotAll,
    };

    HttpRequest(): 
        state_(kExpectRequestLine), 
        method_(kInvalid), 
        version_(kUnknown) {};
    // reset(长连接处理)
    void reset()
    {
        state_ = kExpectRequestLine;
        method_ = kInvalid;
        version_ = kUnknown;
        path_ = "", query_ = "", body_ = "";
        headers_.clear();
    }   

    // 解析请求
    bool parse(Buffer* buf);
    bool got_all() const
    { return state_ == kGotAll; }
  
    // getter
    Method method() const { return method_; }
    std::string method_to_string() const;
    std::string path() const { return path_; }
    std::string query() const { return query_; }
    Version version() const { return version_; }
    const std::unordered_map<std::string, std::string>& headers() const { return headers_; }
    std::string get_header(std::string_view header) const {
        auto it = headers_.find(std::string(header));
        if (it != headers_.end())
            return it->second;
        else
            return std::string();
    }
    std::string body() const { return body_; }

    friend std::ostream& operator<<(std::ostream& os, const HttpRequest& req)
    {
        os << "HttpRequest: state=" << req.state_ 
            << " method=" << req.method_ 
            << " path=" << req.path_ 
            << " query=" << req.query_ 
            << " version=" << req.version_
            << " header size=" << req.headers_.size() 
            << " body=" << req.body_ << std::endl;
        return os;
    }

private:
    // 字符串method转Method
    bool parse_method(const char* start, const char* end);
    // 解析请求行
    bool set_request_line(const char* start, const char* end);

    HttpRequestState state_;
    Method method_;
    std::string path_;
    std::string query_;
    Version version_;
    std::unordered_map<std::string, std::string> headers_;    // 含有content-type
    std::string body_;
};

} // namespace WebREST

#endif