/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-06-16
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <base/Global.h>
#include <base/LoggerAppenderBase.h>
#include <base/LoggerConfigure.h>

namespace Poker::base 
{
class POKER_EXPORT LoggerAppenderStdOut : public LoggerAppenderBase 
{
public:
    LoggerAppenderStdOut() { }
    ~LoggerAppenderStdOut() { }

    QString name();

    int finish();
};
}
