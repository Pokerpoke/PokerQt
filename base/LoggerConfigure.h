/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-07-06
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#pragma once

#include <base/Global.h>
#include <base/Singleton.h>
#include <string>
#include <map>

namespace Poker::base
{
    enum class LoggerLevel
    {
        TRACE,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL,
    };

    enum class LoggerColor
    {
        Red,
        Yellow,
        Blue,
        White,
        Gray,
        Green,
        Default,
    };

    class POKER_EXPORT LoggerConfigure
    {
    public:
        bool changed();

        void set_colored(bool colored)
        {
            m_colored = colored;
        }

        void set_level(const LoggerLevel &level)
        {
            m_level = level;
        }

        LoggerLevel level()
        {
            return m_level;
        }

        bool colored()
        {
            return m_colored;
        }

        static std::string logger_level_str(const LoggerLevel &level);
        static std::string logger_level_color(const LoggerLevel &level);
        static std::string logger_color(const LoggerColor &color);

    private:
        bool m_colored;
        LoggerLevel m_level = LoggerLevel::DEBUG;

        static const std::map<LoggerLevel, std::string> m_logger_level;

        static const std::map<LoggerLevel, LoggerColor> m_logger_level_color;

        static const std::map<LoggerColor, std::string> m_logger_color;
    };

    static auto LoggerConfigureInstance = Singleton<LoggerConfigure>::instance;
}
