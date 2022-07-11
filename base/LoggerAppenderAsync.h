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

#include <memory>
#include <fstream>
#include <thread>
#include <base/LoggerAppenderBase.h>
#include <base/BlockingQueue.h>
#include <base/Global.h>

namespace Poker::base
{
    class POKER_EXPORT LoggerAppenderAsync : public LoggerAppenderBase
    {
    public:
        LoggerAppenderAsync();
        ~LoggerAppenderAsync();

        std::string name()
        {
            return "async";
        }

        virtual int finish();

    private:
        std::string m_file_name = "default.log";
        std::ofstream m_stream;
        std::shared_ptr<std::jthread> m_thread;
        BlockingQueue<std::string> m_queue;
    };
}