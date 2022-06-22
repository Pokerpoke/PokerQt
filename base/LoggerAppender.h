/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2022-06-16
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <memory>
#include <QtCore/QMap>
#include <base/Global.h>
#include <base/LoggerAppenderBase.h>
#include <base/LoggerAppenderStdOut.h>
#include <base/LoggerAppenderAsync.h>
#include <base/Singleton.h>

namespace Poker::base
{
    class POKER_EXPORT LoggerAppender
    {
    public:
        LoggerAppender() {}
        ~LoggerAppender() {}

        void add_appender(std::shared_ptr<LoggerAppenderBase> appender)
        {
            m_appenders.insert(appender->name(), appender);
        }

        std::shared_ptr<LoggerAppenderBase> appender(const QString &name)
        {
            return m_appenders.value(name);
        }

        QList<std::shared_ptr<LoggerAppenderBase>> appenders()
        {
            if (m_appenders.empty())
            {
                add_appender(std::make_shared<LoggerAppenderStdOut>());
            }
            return m_appenders.values();
        }

    private:
        QMap<QString, std::shared_ptr<LoggerAppenderBase>> m_appenders;
    };

    static auto LoggerAppenderInstance = Singleton<LoggerAppender>::instance;
}
