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

#include <iostream>
#include <source_location>
#include <string>
#include <base/LoggerStream.h>

namespace Poker::base
{
    class Logger
    {
    public:
        enum class LogLevel
        {
            TRACE,
            DEBUG,
            INFO,
            WARN,
            ERROR,
            FATAL, // will abort
            ABORT, // will abort
        };

        enum class LogColor
        {
            Black,
            Red,
            Green,
            Yellow,
            Blue,
            Magenta,
            Cyan,
            Default,
        };

    public:
        Logger(Logger::LogLevel level,
               const std::source_location &location,
               bool to_abort = false);

        ~Logger();

        LoggerStream &stream()
        {
            return m_stream;
        }

        // use switch instead of map for constexpr
        constexpr static std::string_view loglevel_name(const Logger::LogLevel &in)
        {
            switch (in)
            {
                using enum Logger::LogLevel;
            case TRACE:
                return "[TRACE]";
            case DEBUG:
                return "[DEBUG]";
            case INFO:
                return "[INFO ]";
            case WARN:
                return "[WARN ]";
            case ERROR:
                return "[ERROR]";
            case FATAL:
                return "[FATAL]";
            case ABORT:
                return "[ABORT]";
            }
        }

        // use switch instead of map for constexpr
        static constexpr std::string_view log_color(const Logger::LogColor &in)
        {
            switch (in)
            {
                using enum Logger::LogColor;
            case Black:
                return "\033[30m";
            case Red:
                return "\033[31m";
            case Green:
                return "\033[32m";
            case Yellow:
                return "\033[33m";
            case Blue:
                return "\033[34m";
            case Magenta:
                return "\033[35m";
            case Cyan:
                return "\033[36m";
            case Default:
                return "\033[0m";
            default:
                return "";
            }
        }

        void set_log_level(const LogLevel &in)
        {
            m_level = in;
        }

        LogLevel log_level() const
        {
            return m_level;
        }

        static void log(Logger::LogLevel, std::string &in, std::source_location &location, bool toAbort = false);

    private:
        // global stream
        LoggerStream m_stream;
        LogLevel m_level;
        std::source_location m_location;
        bool m_abort;
    };
}

#define LOG_TRACE std::cout << "[TRACE] "
#define LOG_DEBUG Poker::base::Logger(Poker::base::Logger::LogLevel::DEBUG, std::source_location::current()).stream() << "[DEBUG] "
#define LOG_INFO std::cout << "[INFO ] "
#define LOG_WARN std::cout << "[WARN ] "
#define LOG_ERROR std::cout << "[ERROR] "
#define LOG_FATAL std::cout << "[FATAL] "
#define LOG_ABORT std::cout << "[ABORT] "