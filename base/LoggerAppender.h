/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-03
 * @brief
 *
 * Last Modified:  2022-03-26
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <base/Singleton.h>

#include <base/noncopyable.h>
#include <base/Singleton.h>
#include <base/LoggerAppenderBase.h>

namespace Poker::base
{
    class LoggerAppender
    {
    public:
        LoggerAppender(/* args */) {}
        ~LoggerAppender() {}

        void add_appender();
        void remove_appender();

        std::list<std::shared_ptr<LoggerAppenderBase>> appenders()
        {
            using namespace std;

            list<shared_ptr<LoggerAppenderBase>> res;

            for (const auto &[key, value] : m_appenders)
            {
                res.push_back(value);
            }

            return res;
        }

        std::shared_ptr<LoggerAppenderBase> appender(const std::string &in);

    private:
        std::map<std::string, std::shared_ptr<LoggerAppenderBase>> m_appenders;
    };

    // 全局配置
    static auto LoggerAppenders = Poker::base::Singleton<Poker::base::LoggerAppender>::instance;
}