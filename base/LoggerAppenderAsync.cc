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
#include "LoggerAppenderAsync.h"
#include <filesystem>

using namespace Poker::base;
using namespace std;

LoggerAppenderAsync::LoggerAppenderAsync()
{
    m_stream.open(m_file_name, ios::out | ios::app);

    m_thread = std::make_shared<std::jthread>([this]() {
        while (true)
        {
            auto str = m_queue.take();

            if (m_stop)
                break;

            if (m_stream.bad())
                continue;

            m_stream << str;
            m_stream.flush();
        }
    });

    m_thread->detach();

    m_configure.set_colored(false);
}

LoggerAppenderAsync::~LoggerAppenderAsync()
{
    m_stop = true;
    m_queue.push(m_stop_queue_flag);
}

int LoggerAppenderAsync::finish()
{
    m_str.append("\n");
    m_queue.push(m_str);
    return m_str.size();
}
