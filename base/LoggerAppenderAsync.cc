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
#include "LoggerAppenderAsync.h"
#include <filesystem>

using namespace Poker::base;
using namespace std;

LoggerAppenderAsync::LoggerAppenderAsync()
{
    m_stream.open(m_file_name, ios::out | ios::app);

    m_thread = std::make_shared<std::jthread>([this]()
                                              {
        while(true)
        {
        auto str = m_queue.take();

        if (m_stream.bad())
            continue;

        m_stream << str;
        } });

    m_thread->detach();
}

LoggerAppenderAsync::~LoggerAppenderAsync()
{
}

int LoggerAppenderAsync::finish()
{
    m_queue.push(m_str);
    return m_str.size();
}
