/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-03-26
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#pragma once
#include <memory>
#include <base/LoggerConfigure.h>
#include <base/LoggerStream.h>

namespace Poker::base
{
    // start -> finish -> log
    class LoggerAppenderBase
    {
    public:
        using LoggerAppenderBasePtr = std::shared_ptr<LoggerAppenderBase>;

    public:
        LoggerAppenderBase() {}
        ~LoggerAppenderBase() {}

        virtual void start() = 0;

        virtual void log() = 0;

        virtual void finish() = 0;

        LoggerConfigure &configure()
        {
            return m_configure;
        }

        LoggerStream &stream()
        {
            return m_stream;
        }

    private:
        LoggerConfigure m_configure;
        LoggerStream m_stream;
    };
}