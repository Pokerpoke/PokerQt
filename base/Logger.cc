/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-03-26
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include "Logger.h"
#include "LoggerAppender.h"
#include <map>

using namespace Poker::base;

namespace
{
}

Logger::Logger(Logger::LogLevel level,
               const std::source_location &location,
               bool to_abort)
    : m_level(level),
      m_location(location),
      m_abort(to_abort)
{
}

Logger::~Logger()
{
    for (const auto &appender : LoggerAppenders().appenders())
    {
        appender->finish();

        appender->log();
    }

    if (m_level == LogLevel::ABORT)
    {
        abort();
    }
}
