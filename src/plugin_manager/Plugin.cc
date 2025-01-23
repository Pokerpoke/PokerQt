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
#include <PokerQt/plugin_manager/Plugin.h>
#include <PokerQt/base/logger.h>

namespace Poker::plugin
{

Plugin::Plugin()
{
}

Plugin::~Plugin()
{
}

std::string Plugin::name()
{
    return "BasePlugin";
}

void Plugin::init()
{
}
void Plugin::uninit()
{
}

std::pair<int, std::string> Plugin::command(const std::string &cmd)
{
    spdlog::debug("Plugin {} run command {}", name(), cmd);
    return {0, "succeed"};
}

} // namespace Poker::plugin