/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-03
 * @brief
 *
 * Last Modified:  2022-07-06
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include <thread>
#include "base/BlockingQueue.h"
#include "base/Logger.h"

using namespace Poker::base;
using namespace std;

int main(int argc, char const *argv[])
{
    BlockingQueue<int> q;

    std::thread worker([&q]
                       {
            while(1)
            {
                auto res = q.take();
                LOG_INFO << res;
            } });
    worker.detach();

    std::thread consumer([&q]
                         { 
                             for(int i = 0; i < 10; i++){
                                 LOG_DEBUG << i;
                                 q.push(i);
                                 std::this_thread::sleep_for(1s);
                              } });
    consumer.detach();

    getchar();

    return 0;
}
