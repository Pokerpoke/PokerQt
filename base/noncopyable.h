/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-03
 * @brief
 *
 * Last Modified:  2022-06-16
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#pragma once

#include <base/Global.h>

namespace Poker::base
{
    class POKER_EXPORT noncopyable
    {
    protected:
        noncopyable() = default;
        ~noncopyable() = default;

    private:
        noncopyable(const noncopyable &) = delete;
        noncopyable &operator=(const noncopyable) = delete;
    };
}