/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-02
 * @brief
 *
 * Last Modified:  2022-03-20
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#pragma once

#include <mutex>
#include <deque>
#include <condition_variable>
#include <base/noncopyable.h>

namespace Poker::base
{
    template <typename DataType>
    class BlockingQueue : noncopyable
    {
    public:
        BlockingQueue() {}
        ~BlockingQueue() {}

        void push(const DataType &in)
        {
            {
                std::scoped_lock lck(m_mutex);
                m_queue.push_back(in);
            }
            m_cv.notify_one();
        }

        void push(DataType &&in)
        {
            {
                std::scoped_lock lck(m_mutex);
                m_queue.push_back(std::move(in));
            }
            m_cv.notify_one();
        }

        DataType take()
        {
            std::unique_lock<std::mutex> lck(m_mutex);
            m_cv.wait(lck, [this]
                      { return !this->m_queue.empty(); });

            DataType res(std::move(m_queue.front()));
            m_queue.pop_front();
            return res;
        }

        size_t size()
        {
            std::scoped_lock lck(m_mutex);
            return m_queue.size();
        }

        bool empty()
        {
            std::scoped_lock lck(m_mutex);
            return m_queue.empty();
        }

    private:
        std::mutex m_mutex;
        std::deque<DataType> m_queue;
        std::condition_variable m_cv;
    };
}