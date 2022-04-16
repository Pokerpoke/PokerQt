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

#pragma once

#include <base/LoggerAppenderBase.h>

namespace Poker::base
{
    class LoggerAppenderSTDOUT : LoggerAppenderBase
    {
    public:
        LoggerAppenderSTDOUT() {}
        ~LoggerAppenderSTDOUT() {}

        void start();

        void finish();

        void log();
    };
}