/*
 * @Author: HH
 * @Date: 2023-04-07 22:40:31
 * @LastEditTime: 2023-04-14 21:57:57
 * @LastEditors: sunburst7 1064658281@qq.com
 * @Description: 
 * @FilePath: /WebREST/WebREST/core/http_request.cc
 */

#ifndef WebREST_HTTP_REQUEST_CC_
#define WebREST_HTTP_REQUEST_CC_

#include "http_request.h"
#include "buffer.h"

using namespace WebREST;

bool HttpRequest::parse_method(const char* start, const char* end)
{
    std::string tmp(start, end);
    bool ret = true;
    if (tmp == "GET")
        method_ = kGet;
    else if(tmp == "POST")
        method_ = kPost;
    else if (tmp == "PUT")
        method_ = kPut;
    else if (tmp == "DELETE")
        method_ = kDeleted;
    else if (tmp == "OPTIONS")
        method_ = kOptions;
    else 
        ret = false;

    return ret;
}

std::string HttpRequest::method_to_string() const {
    if (method_ == kGet)
        return "GET";
    else if (method_ == kPost)
        return "POST";
    else if (method_ == kPut)
        return "PUT";
    else if (method_ == kDeleted)
        return "DELETE";
    else if (method_ == kOptions)
        return "OPTIONS";
    else 
        return "INVALID";
}

bool HttpRequest::set_request_line(const char* start, const char* end)
{
    const char* begin = start;
    // method
    const char* space = std::find(begin, end, ' ');
    if (space == end || !parse_method(begin, space)) return false;
    begin = space + 1;

    // path + query
    space = std::find(begin, end, ' ');
    if (space == end) return false;

    const char* query = std::find(begin, space, '?');
    if (query != space)
    {
        path_.assign(begin, query);
        query_.assign(query + 1, space);
    }
    else
        path_.assign(begin, space);

    // version
    const std::string ver_prefix = "HTTP/1.";
    begin = std::search(start, end, ver_prefix.begin(), ver_prefix.end());    // 查找字符串
    if (begin == end) return false;
    
    const char num = *(begin + ver_prefix.size());
    if (num == '1')
        version_ = kHttp11;
    else if (num == '0')
        version_ = kHttp10;
    else 
        return false;
    
    state_ = kExpectHeaders;
    return true;
}

bool HttpRequest::parse(Buffer* buf)
{
    bool ok = true;
    while (true)
    {
        if (state_ == kExpectRequestLine)
        { 
            const char* crlf = buf->find_CRLF();
            if (crlf)
            {
                ok = set_request_line(buf->begin_read(), crlf);
                if (ok)
                {
                    buf->retrieve_until(crlf + 2);
                    state_ = kExpectHeaders;
                }
                else break;
            }
            else break;
        }
        else if (state_ == kExpectHeaders)
        {
            const char* crlf = buf->find_CRLF();
            if (crlf)
            {
                const char* colon = std::find(const_cast<const char*>(buf->begin_read()), crlf, ':');
                // 存在请求头
                if (colon != crlf)
                    headers_[std::move(std::string(const_cast<const char*>(buf->begin_read()), colon))] = std::move(std::string(colon + 1, crlf));
                else
                {
                    // 空行，此时头读取为空
                    if (method_ == kGet) {
                        state_ = kGotAll;   // 状态机出口1
                        buf->retrieve_until(crlf + 2);
                        break;
                    }
                    else
                    {
                        state_ = kExpectBody;
                    }

                }
                buf->retrieve_until(crlf + 2);
            }
            else 
            {
                break;
            }
        }
        else if (state_ == kExpectBody)
        {
            if (buf->readable_bytes() > 0)
                body_.assign(buf->begin_read(), buf->begin_write());
            else 
                body_ = std::string();
            state_ = kGotAll;             // 状态机出口2
            break;
        }
    }
    return ok;
}


#endif