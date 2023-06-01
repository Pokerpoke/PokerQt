/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2022-11-05
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include <base/Logger.h>
#include <base/LoggerAppenderAsync.h>
#include <base/LoggerAppenderSTDOUT.h>

using namespace Poker::base;

int main(int argc, char const *argv[])
{
    // Logger logger;
    auto ptr = std::make_shared<LoggerAppenderAsync>();

    ptr->start(LoggerLevel::DEBUG, std::source_location::current());
    ptr->log("elksje");
    ptr->finish();
    LoggerAppenderInstance().add_appender(std::make_shared<LoggerAppenderAsync>());
    LoggerAppenderInstance().add_appender(std::make_shared<LoggerAppenderStdOut>());

    // {
    //     LoggerAppenderStdOut log;
    //     log.start(LoggerLevel::DEBUG, std::source_location::current());
    //     log.log("sdklfjl");
    //     log.finish();
    // }

    for (int i = 0; i < 100; i++)
    {
        LOG_TRACE << "trace";
        LOG_DEBUG << "debug";
        LOG_INFO << "info";
        LOG_WARN << "warn";
        LOG_ERROR << "error";
        LOG_FATAL << "fatal";
    }

    return 0;
}
