/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-02-22
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

namespace Poker::base
{
    template <typename T>
    class Singleton
    {
    public:
        static T &instance()
        {
            static T t;
            return t;
        }

    private:
        Singleton() = default;
        Singleton(const Singleton &) = delete;
        Singleton &operator=(const Singleton) = delete;
    };
}