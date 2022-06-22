/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2022-06-19
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

namespace Poker::base
{
    class EventLoop
    {
    public:
        EventLoop(/* args */) {}
        ~EventLoop() {}

        void start();
        void stop();
    };
}