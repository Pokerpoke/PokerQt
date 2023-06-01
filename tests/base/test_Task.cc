/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2022-06-23
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include <base/Task.h>
#include <string>
#include <base/Logger.h>

using namespace Poker::base;

int test_task(int i)
{
    static int j = 0;
    LOG_DEBUG << "test " << j;
    j++;
    i++;
    return i;
};

int main(int argc, char const *argv[])
{
    LoggerConfigureInstance().set_level(LoggerLevel::TRACE);

    Task<int(int)> task(test_task);

    auto res = task.then(test_task)
                   .then(test_task)
                   .then(test_task)
                   .run(1);

    LOG_DEBUG << res;

    // task.run();

    return 0;
}
