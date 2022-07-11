/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-07
 * @brief
 *
 * Last Modified:  2022-07-07
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <base/Global.h>
#include <string>
#include <chrono>
#include <format>

namespace Poker::base
{
    inline std::string get_current_time_and_date()
    {
        auto const time = std::chrono::current_zone()
                              ->to_local(std::chrono::system_clock::now());

        return std::format("{:%Y-%m-%d %X}", time);
    }
}