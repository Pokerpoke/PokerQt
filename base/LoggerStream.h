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

// #include <QtCore/QByteArray>
#include <string>

namespace Poker::base
{
    class LoggerStream
    {

    public:
        using self = LoggerStream;

        LoggerStream() {}
        ~LoggerStream() {}

        std::string &string()
        {
            return m_stream;
        }

        self &operator<<(const std::string &in)
        {
            m_stream.append(in);
            return *this;
        }

        self &operator<<(int in)
        {
            m_stream.append(std::to_string(in));
            return *this;
        }

    private:
        std::string m_stream;
    };
}