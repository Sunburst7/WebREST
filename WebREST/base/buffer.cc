/*
 * @Author: HH
 * @Date: 2023-04-07 21:48:39
 * @LastEditTime: 2023-04-08 00:00:58
 * @LastEditors: HH
 * @Description: 
 * @FilePath: /WebREST/WebREST/base/buffer.cc
 */
#ifndef WebREST_BUFFER_CC_
#define WebREST_BUFFER_CC_

#include "buffer.h"
#include <errno.h>
#include <sys/uio.h>

using namespace WebREST;

const char Buffer::kCRLF[] = "\r\n";

int WebREST::Buffer::read_fd(int fd, int &saveError)
{
    char extrabuf[65536];
    struct iovec vec[2]; // buffer_ 和 extrabuf
    const size_t writable = writable_bytes();
    vec[0].iov_base = begin() + write_index_;
    vec[0].iov_len = writable;
    vec[1].iov_base = extrabuf;
    vec[1].iov_len = sizeof extrabuf;

    // 如果读入的数据不多，那么全部都读到Buffer中去了；
    // 如果长度超过Buffer的writable字节数，就会读到栈上的extrabuf里，然后程序再把extrabuf里的数据append()到Buffer中
    const int iovcnt = (writable < sizeof extrabuf) ? 2 : 1;
    const ssize_t n = ::readv(fd, vec, iovcnt);
    if (n < 0)
    {
        saveError = errno;
    }
    else if ((size_t)n <= writable)
    {
        write_index_ += n;
    }
    else
    {
        write_index_ = buffer_.size();
        append(extrabuf, n - writable);
    }
    return n;
}

void Buffer::makesure_enough_storage(size_t len)
{
    if ( writable_bytes() >= len ) return;
    // 可以通过内部腾挪插入
    if ( writable_bytes() + prependable_bytes() >= len + kPrependIndex )
    {
        std::copy(begin_read(), begin_write(), begin() + kPrependIndex);
        read_index_ = kPrependIndex;
        write_index_ = kPrependIndex + readable_bytes();
    }
    else 
    {
        buffer_.resize(write_index_ + len);
    }
}



#endif
