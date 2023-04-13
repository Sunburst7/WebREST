/*
 * @Author: HH
 * @Date: 2023-04-07 21:08:14
 * @LastEditTime: 2023-04-13 00:26:54
 * @LastEditors: sunburst7 1064658281@qq.com
 * @Description: 缓冲区
 * @FilePath: /Enhance_Tiny_muduo/WebREST/base/buffer.h
 */

#ifndef WebREST_BUFFER_H_
#define WebREST_BUFFER_H_

#include "copyable.h"

#include <assert.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string_view>

namespace WebREST {

class Buffer: Copyable{
public:
    static const size_t kPrependIndex = 8;
    static const size_t kInitialSize = 1024;

    explicit Buffer(size_t initial_size = kInitialSize) : 
        buffer_(kPrependIndex + initial_size), 
        read_index_(kPrependIndex), 
        write_index_(kPrependIndex) {};

    // 从socket fd中读取data
    // 
    int read_fd(int fdm ,int& saveError);

    char* begin_read() { return begin() + read_index_; }
    const char* begin_read() const { return begin() + read_index_; }

    char* begin_write() { return begin() + write_index_; }
    const char* begin_write() const { return begin() + write_index_; } 

    const std::string peek_as_string() const
    { return std::string(begin_read(), begin_write()); }
    const std::string peek_as_string(int len) const
    { return std::string(begin_read(), begin_read() + len); }

    void append(const char* message, int len)
    {
        makesure_enough_storage(len);
        std::copy(message, message + len, begin_write());
        write_index_ += len;
    }
    void append(std::string_view message)
    {
        append(message.data(), message.size());
    }
  
    // 调整read_index_
    void retrieve(int len)
    {
        if (len < readable_bytes())
            read_index_ += len;
        else
            retrieve_all(); // len == readable_bytes()时表示全部读完，复位
    }
    // 调整read_index至end处
    void retrieve_until(const char* end)
    {
        assert(begin_read() <= end);
        assert(end <= begin_write());
        retrieve(end - begin_read());
    }
    // 复位
    void retrieve_all()
    {
        read_index_ = kPrependIndex;
        write_index_ = kPrependIndex;
    }
    std::string retrieve_as_string(size_t len)
    {
        assert(len <= readable_bytes());
        std::string res(begin_read(), len);
        retrieve(len);
        return res;
    }
    std::string retrieve_all_as_string() { return retrieve_as_string(readable_bytes()); }
  
    size_t readable_bytes() const { return write_index_ - read_index_; }
    size_t writable_bytes() const { return buffer_.size() - write_index_; }
    size_t prependable_bytes() const { return read_index_; }

    const char* find_CRLF() const 
    {
        const char* crlf = std::search(begin_read(), begin_write(), kCRLF, kCRLF + 2);
        return crlf == begin_write() ? nullptr : crlf;
    }

private:
    char* begin() { return &*buffer_.begin(); }
    const char* begin() const { return &*buffer_.begin(); }
    // 根据即将要写入的长度len判断是否能够写入，不够需要扩容
    void makesure_enough_storage(size_t len);
  
    std::vector<char> buffer_;
    int read_index_;               // 下一个可以读取的字符的index
    int write_index_;              // 下一个可以写入的字符的index
    static const char kCRLF[];
};

} // namespace WebREST

#endif
