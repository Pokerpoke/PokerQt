/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2025-01-20
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <functional>
#include <PokerQt/base/Logger.h>

namespace Poker::base
{
template <typename T>
class Task;

template <typename R, typename... Args>
class Task<R(Args...)>
{

public:
    // 移动构造函数
    Task(std::function<R(Args...)> &&f) : m_fn(std::move(f))
    {
        spdlog::trace("Task move contruct func");
    }
    // 普通构造函数
    Task(std::function<R(Args...)> &f) : m_fn(f)
    {
        spdlog::trace("Task contruct func");
    }

    R run(Args &&...args)
    {
        spdlog::trace("Task exec function ");

        return m_fn(std::forward<Args>(args)...);
    }

    template <typename F>
    auto then(F &&f) -> Task<typename std::invoke_result<F, R>::type(Args...)>
    {
        spdlog::trace("Task then");
        auto func = std::move(m_fn);

        using return_type = typename std::invoke_result<F, R>::type;

        return Task<return_type(Args...)>(
            [func, f](Args &&...args)
            {
                return f(func(std::forward<Args>(args)...));
            });
    }

private:
    std::function<R(Args...)> m_fn;
};

} // namespace Poker::base