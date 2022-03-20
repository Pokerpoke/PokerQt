/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-03
 * @brief
 *
 * Last Modified:  2022-03-20
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

namespace Poker::base
{
    class noncopyable
    {
    protected:
        noncopyable() = default;
        ~noncopyable() = default;

    private:
        noncopyable(const noncopyable &) = delete;
        noncopyable &operator=(const noncopyable) = delete;
    };
}