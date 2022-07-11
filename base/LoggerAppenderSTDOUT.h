/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-07-04
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <base/Global.h>
#include <base/LoggerAppenderBase.h>
#include <base/LoggerConfigure.h>
#include <string>

namespace Poker::base
{
    class POKER_EXPORT LoggerAppenderStdOut : public LoggerAppenderBase
    {
    public:
        LoggerAppenderStdOut() {}
        ~LoggerAppenderStdOut() {}

        std::string name();

        int finish();
    };
}
