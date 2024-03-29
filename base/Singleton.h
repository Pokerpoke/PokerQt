/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-08-22
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <base/Global.h>
#include <base/noncopyable.h>

namespace Poker::base
{
    template <typename T>
    class POKER_EXPORT Singleton : noncopyable
    {
    public:
        static T &instance()
        {
            static T t;
            return t;
        }
    };
}