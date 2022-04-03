/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-02
 * @brief
 *
 * Last Modified:  2022-03-26
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <base/noncopyable.h>

#include <string>
#include <string_view>

namespace Poker::base
{
    template <typename T>
    concept Stringable = requires(T x)
    {
        std::to_string(x);
    };

    class LoggerStream : noncopyable
    {
    public:
        using self = LoggerStream;

    public:
        LoggerStream()
        {
        }
        ~LoggerStream()
        {
        }

        template <typename T>
        requires Stringable<T>
            self &operator<<(T in)
        {
            m_data.append(std::to_string(in));
            return *this;
        }

        // self &operator<<(const std::string &in)
        // {
        //     m_data.append(in);
        //     return *this;
        // }

        // template <typename T>
        // requires std::same_as<std::string_view, T>
        self &operator<<(const std::string_view &in)
        {
            m_data.append(in);
            return *this;
        }

    private:
        std::string m_data;
    };
}