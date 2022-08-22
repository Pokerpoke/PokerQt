/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2022-08-22
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <memory>
#include <map>
#include <base/Global.h>
#include <base/LoggerAppenderBase.h>
#include <base/LoggerAppenderStdOut.h>
#include <base/Singleton.h>
#include <functional>
#include <list>

namespace Poker::base
{
    class POKER_EXPORT LoggerAppender
    {
    public:
        void add_appender(std::shared_ptr<LoggerAppenderBase> appender)
        {
            m_appenders.emplace(appender->name(), appender);
        }

        std::shared_ptr<LoggerAppenderBase> appender(const std::string &name)
        {
            return m_appenders.at(name);
        }

        std::list<std::shared_ptr<LoggerAppenderBase>> appenders()
        {
            std::list<std::shared_ptr<LoggerAppenderBase>> res;

            if (m_appenders.empty())
            {
                add_appender(std::make_shared<LoggerAppenderStdOut>());
            }

            for (const auto &[key, value] : m_appenders)
            {
                res.emplace_back(value);
            }
            return res;
        }

    private:
        std::map<std::string, std::shared_ptr<LoggerAppenderBase>> m_appenders;
    };

    static auto LoggerAppenderInstance = Singleton<LoggerAppender>::instance;
}
