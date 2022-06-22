/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2022-06-16
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <base/LoggerAppenderBase.h>
#include <base/Global.h>

namespace Poker::base
{
    class POKER_EXPORT LoggerAppenderAsync : public LoggerAppenderBase
    {
    public:
        LoggerAppenderAsync();
        ~LoggerAppenderAsync();

        QString name()
        {
            return "async";
        }
    };
}