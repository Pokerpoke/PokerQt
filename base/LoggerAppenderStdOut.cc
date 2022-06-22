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
#include "LoggerAppenderStdOut.h"
#include <iostream>

using namespace Poker::base;

QString LoggerAppenderStdOut::name()
{
    return "stdout";
}

int LoggerAppenderStdOut::finish()
{
    std::cout << m_str.toStdString() << std::endl;

    return m_str.size();
}
