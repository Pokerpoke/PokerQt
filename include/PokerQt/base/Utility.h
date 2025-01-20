/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-07
 * @brief
 *
 * Last Modified:  2025-01-20
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <PokerQt/base/base_global.h>
#include <string>
#include <chrono>
#include <fmt/format.h>
#include <fmt/chrono.h>

namespace Poker::base
{
inline POKERQT_BASE_EXPORT std::string get_current_time_and_date()
{
    auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());

    return fmt::format("{:%Y-%m-%d %X}", time);
}
} // namespace Poker::base