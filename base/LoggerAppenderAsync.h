/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2022-11-26
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <memory>
#include <fstream>
#include <thread>
#include <atomic>
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

        int start(const LoggerLevel &level, const std::source_location location)
        {
            auto time = get_current_time_and_date();

            auto log_level_str = LoggerConfigure::logger_level_str(level);

            m_str = std::format("{} [{}] {}:{} {} - ", time, log_level_str, location.file_name(),
                                location.line(), location.function_name());

            return m_str.size();
        }

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
        std::atomic_bool m_stop = false;

        const std::string m_stop_queue_flag = "LoggerAppenderAsync::Stop_queue";
    };
} // namespace Poker::base