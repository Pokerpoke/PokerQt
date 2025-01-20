/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-03
 * @brief
 *
 * Last Modified:  2025-01-20
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include <thread>
#include "PokerQt/base/BlockingQueue.h"
#include <spdlog/spdlog.h>

using namespace Poker::base;
using namespace std;

int main(int argc, char const *argv[])
{
    BlockingQueue<int> q;

    std::thread worker([&q] {
        while (1)
        {
            auto res = q.take();
            spdlog::info(res);

            if (res == 9)
            {
                break;
            }
        }
    });
    worker.detach();

    std::thread consumer([&q] {
        for (int i = 0; i < 10; i++)
        {
            spdlog::debug(i);
            q.push(i);
            std::this_thread::sleep_for(1s);
        }
    });
    consumer.join();

    return 0;
}
