//
//  _THREAD_GUARD.h
//  TinyThreadPool
//
//  Created by maochongxin on 2018/12/26.
//  Copyright © 2018 Maochongxin. All rights reserved.
//

#ifndef _THREAD_GUARD_H_
#define _THREAD_GUARD_H_

#include <utility>
#include <vector>

template <class ThreadType>
class thread_guard {
private:
    std::vector<ThreadType> threads_;
public:
    thread_guard(std::vector<ThreadType>& vec) : threads_(vec){}
    
    thread_guard(thread_guard& tg) = delete;
    thread_guard& operator= (thread_guard&& tg) = delete;
    
    thread_guard(const thread_guard&) = delete;
    thread_guard& operator= (const thread_guard&) = delete;
    
    ~thread_guard() {
        for (size_t i = 0; i < threads_.size(); i++) {
            if (threads_[i].joinable()) {
                threads_[i].join();
            }
        }
    }
    
};


#endif /* _THREAD_GUARD_h */
