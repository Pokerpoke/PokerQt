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

#include <QtCore/QDateTime>
#include <QtCore/QString>
#include <base/Global.h>
#include <base/LoggerConfigure.h>
#include <base/noncopyable.h>
#include <source_location>

namespace Poker::base
{
    class POKER_EXPORT LoggerAppenderBase
    {
    public:
        LoggerAppenderBase() {}

        virtual ~LoggerAppenderBase() {}

        virtual QString name() = 0;

        virtual int start(const LoggerLevel &level, const std::source_location location)
        {
            // yyyy-MM-dd hh:mm:ss.zzz [INFO ] fil_name:line funtion_name - log str
            m_str = std::move(QString("%1 [%2] %3:%4 %5 - ")
                                  .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz"))
                                  .arg(LoggerConfigure::logger_level_color(level) +
                                       LoggerConfigure::logger_level_str(level) +
                                       LoggerConfigure::logger_color(LoggerColor::Default))
                                  .arg(location.file_name())
                                  .arg(location.line())
                                  .arg(location.function_name()));

            return m_str.size();
        }

        virtual int log(const QString &log_str)
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

        QString m_str;
    };
}