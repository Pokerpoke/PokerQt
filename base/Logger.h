/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-06-17
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#pragma once

#include <iostream>
#include <base/Global.h>
#include <base/LoggerAppender.h>
#include <base/LoggerConfigure.h>
#include <base/LoggerStream.h>
#include <base/Singleton.h>
#include <source_location>

namespace Poker::base
{
    class POKER_EXPORT Logger
    {
    public:
        Logger(const LoggerLevel &level,
               const std::source_location location)
        {

            for (const auto &appender : LoggerAppenderInstance().appenders())
            {
                appender->start(level, location);
            }
        }

        LoggerStream &stream()
        {
            return m_stream;
        }

        ~Logger()
        {
            for (const auto &appender : LoggerAppenderInstance().appenders())
            {
                appender->log(m_stream.string());
                appender->finish();
            }
        }

    private:
        LoggerStream m_stream;
    };
}

#define LOG_TRACE                                                                          \
    if (Poker::base::LoggerConfigureInstance().level() <= Poker::base::LoggerLevel::TRACE) \
    Poker::base::Logger(Poker::base::LoggerLevel::TRACE, std::source_location::current()).stream()

#define LOG_DEBUG                                                                          \
    if (Poker::base::LoggerConfigureInstance().level() <= Poker::base::LoggerLevel::DEBUG) \
    Poker::base::Logger(Poker::base::LoggerLevel::DEBUG, std::source_location::current()).stream()

#define LOG_INFO                                                                          \
    if (Poker::base::LoggerConfigureInstance().level() <= Poker::base::LoggerLevel::INFO) \
    Poker::base::Logger(Poker::base::LoggerLevel::INFO, std::source_location::current()).stream()

#define LOG_WARN                                                                          \
    if (Poker::base::LoggerConfigureInstance().level() <= Poker::base::LoggerLevel::WARN) \
    Poker::base::Logger(Poker::base::LoggerLevel::WARN, std::source_location::current()).stream()

#define LOG_ERROR                                                                          \
    if (Poker::base::LoggerConfigureInstance().level() <= Poker::base::LoggerLevel::ERROR) \
    Poker::base::Logger(Poker::base::LoggerLevel::ERROR, std::source_location::current()).stream()

#define LOG_FATAL                                                                          \
    if (Poker::base::LoggerConfigureInstance().level() <= Poker::base::LoggerLevel::FATAL) \
    Poker::base::Logger(Poker::base::LoggerLevel::FATAL, std::source_location::current()).stream()