/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2022-06-17
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include <base/Logger.h>

using namespace Poker::base;

int main(int argc, char const *argv[])
{
    // Logger logger;

    {
        LoggerAppenderStdOut log;
        log.start(LoggerLevel::DEBUG, std::source_location::current());
        log.log("sdklfjl");
        log.finish();
    }

    LOG_TRACE << "trace";
    LOG_DEBUG << "debug";
    LOG_INFO << "info";
    LOG_WARN << "warn";
    LOG_ERROR << "error";
    LOG_FATAL << "fatal";

    return 0;
}
