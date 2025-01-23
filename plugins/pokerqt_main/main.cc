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
#include <PokerQt/plugin_manager/PluginManager.h>
#include <PokerQt/base/logger.h>
#include <filesystem>

using namespace Poker::plugin;

int main(int argc, const char **argv)
{
    auto cur_path = std::filesystem::current_path();

    auto p = PluginManagerInstance().load(cur_path.string() + "/someip_plugin", "someip_plugin");

    p->command("init");

    spdlog::info("Hello, www!");
    return 0;
}