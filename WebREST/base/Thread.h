/*
 * @Author: HH
 * @Date: 2023-04-05 01:16:07
 * @LastEditTime: 2023-04-05 05:21:45
 * @LastEditors: HH
 * @Description: 封装的thread类
 * @FilePath: /WebREST/WebREST/base/Thread.h
 */
#ifndef WebREST_THREAD_H_
#define WebREST_THREAD_H_

#include <thread>
#include <functional>
#include <assert.h>
#include "non_copyable.h"
#include "countdown_latch.h"

namespace WebREST {

class Thread: NonCopyable {
public:
    using ThreadFunc = std::function<void()>;
    Thread(const ThreadFunc& func): 
        started_(false), 
        joined_(false), 
        func_(func), 
        latch_(1){};
    ~Thread() { 
        if (!joined_)
            thread_.detach();
    }

    bool is_started() { return started_; }
    void join() {
        assert(started_);
        if (!joined_) {
            joined_ = true;
            thread_.join();
        }
    }

    void start_thread();

private:
    void run_in_thread();    // 确保主线程能等待子线程运行完毕

    bool started_;           // thread is start runing func_
    bool joined_;            // thread is joined
    std::thread thread_;
    ThreadFunc func_;
    CountDownLatch latch_;
};

} // namespace WebREST

#endif