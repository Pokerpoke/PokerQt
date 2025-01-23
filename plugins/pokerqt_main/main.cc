/**
 *
 * Copyright (c) 2025 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2025-01
 * @brief
 *
 * Last Modified:  2025-01-23
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include "spdlog/common.h"
#include "spdlog/spdlog.h"
#include <PokerQt/plugin_manager/PluginManager.h>
#include <PokerQt/base/logger.h>
#include <boost/filesystem/path.hpp>
#include <boost/dll.hpp>
#include <filesystem>

using namespace Poker::plugin;

int main(int argc, const char **argv)
{
    spdlog::set_level(spdlog::level::debug);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [thread %t] %v");

    auto cur_path = std::filesystem::current_path();

    auto p = PluginManagerInstance().load(cur_path.string() + "/someip_plugin");

    if (!p)
    {
        spdlog::error("Load plugin failed!");
        return -1;
    }

    p->command("init");
    spdlog::debug("Plugin name: {}", p->name());

    return 0;
}