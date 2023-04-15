/*
 * @Author: HH
 * @Date: 2023-04-05 00:55:44
 * @LastEditTime: 2023-04-05 01:07:30
 * @LastEditors: HH
 * @Description: 利用互斥量与条件变量构成的倒计时器
 * @FilePath: /WebREST/WebREST/base/countdown_latch.h
 */

#ifndef WebREST_COUNTDOWN_LATCH_H_
#define WebREST_COUNTDOWN_LATCH_H_

#include <mutex>
#include <condition_variable>

#include "non_copyable.h"

namespace WebREST {

class CountDownLatch : NonCopyable {
public:
    explicit CountDownLatch(int count): count_(count), mutex_(), cv_(){};

    int get_count() const { return count_; }

    // 计数 - 1，当减为0时通知所有等待者
    void count_down();

    // 等待直到count_ = 0
    void wait();

private:
    int count_;
    std::mutex mutex_;
    std::condition_variable cv_;
};

} // namespace WebREST

#endif
