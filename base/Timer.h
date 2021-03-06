/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2022-07-04
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <base/Global.h>

namespace Poker::base
{
    class POKER_EXPORT Timer
    {
    public:
        Timer() {}
        ~Timer() {}

        static void single_shot() {}
    };
}