/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-07-04
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <format>
#include <base/Global.h>
#include <base/LoggerConfigure.h>
#include <base/noncopyable.h>
#include <source_location>
#include <base/Utility.h>

namespace Poker::base
{
    class POKER_EXPORT LoggerAppenderBase
    {
    public:
        LoggerAppenderBase() {}

        virtual ~LoggerAppenderBase() {}

        virtual std::string name() = 0;

        virtual int start(const LoggerLevel &level, const std::source_location location)
        {
            auto time = get_current_time_and_date();

            auto log_level_str = LoggerConfigure::logger_level_color(level)
                                     .append(LoggerConfigure::logger_level_str(level))
                                     .append(LoggerConfigure::logger_color(LoggerColor::Default));

            m_str = std::format("{} [{}] {}:{} {} - ", time,
                                log_level_str,
                                location.file_name(),
                                location.line(),
                                location.function_name());

            return m_str.size();
        }

        virtual int log(const std::string &log_str)
        {
            m_str.append(log_str);
            return log_str.size();
        }

        virtual int finish()
        {
            return m_str.size();
        }

    protected:
        LoggerConfigure m_configure;

        std::string m_str;
    };
}