/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-02-22
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <iostream>

namespace Poker::base
{
    class Logger
    {
    private:
        /* data */
    public:
        Logger();
        ~Logger();
    };
}

#define LOG_DEBUG std::cout << "[DEBUG] "
#define LOG_INFO std::cout << "[INFO ] "
#define LOG_WARN std::cout << "[WARN ] "
#define LOG_ERROR std::cout << "[ERROR] "
#define LOG_FATAL std::cout << "[FATAL] "