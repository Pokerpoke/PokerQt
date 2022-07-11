/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-07-06
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <base/noncopyable.h>

namespace Poker::base
{
    template <typename T>
    class Singleton : noncopyable
    {
    public:
        static T &instance()
        {
            static T t;
            return t;
        }

        // private:
        //     Singleton() = default;
        //     ~Singleton() = default;
        //     Singleton(const Singleton &) = delete;
        //     Singleton &operator=(const Singleton) = delete;
    };
}