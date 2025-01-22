/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-03
 * @brief
 *
 * Last Modified:  2025-01-22
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include <thread>
#include <blockingconcurrentqueue.h>
#include <spdlog/spdlog.h>

// using namespace Poker::base;
using namespace std;

int main(int argc, char const *argv[])
{
    // BlockingQueue<int> q;
    using DataType = int;
    moodycamel::BlockingConcurrentQueue<DataType> q;

    std::thread worker(
        [&q]
        {
            spdlog::info("worker start");
            while (1)
            {
                DataType res;
                q.wait_dequeue(res);
                spdlog::info("poped {}", res);
            }
        });
    worker.detach();

    std::thread producer(
        [&q]
        {
            for (int i = 0; i < 10; i++)
            {
                spdlog::debug(i);
                q.enqueue(i);
                spdlog::info("pushed {}", i);
                std::this_thread::sleep_for(1s);
            }
        });
    producer.join();

    return 0;
}
