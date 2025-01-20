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

#pragma once

#include <PokerQt/base/base_global.h>

namespace Poker::base
{
class POKERQT_BASE_EXPORT noncopyable
{
protected:
    noncopyable()  = default;
    ~noncopyable() = default;

private:
    noncopyable(const noncopyable &)          = delete;
    noncopyable &operator=(const noncopyable) = delete;
};
} // namespace Poker::base