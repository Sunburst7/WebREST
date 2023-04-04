/*
 * @Author: HH
 * @Date: 2023-03-31 01:20:39
 * @LastEditTime: 2023-03-31 19:00:26
 * @LastEditors: HH
 * @Description: NonCopyable base class, base on boost::noncopyable
 * @FilePath: /light_server/WebREST/util/non_copyable.h
 */
#ifndef WebREST_NONCOPYABLE_H_
#define WebREST_NONCOPYABLE_H_


namespace WebREST {

class NonCopyable {
protected:
    NonCopyable() = default;
    ~NonCopyable() = default;
private:
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};

} // namespace WebREST

#endif