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

#include "someip_plugin.h"
#include <PokerQt/base/logger.h>

using namespace Poker::plugin;

SomeipPlugin::SomeipPlugin() : Poker::plugin::Plugin()
{
}

SomeipPlugin::~SomeipPlugin()
{
}

std::string SomeipPlugin::name()
{
    return "SomeipPlugin";
}

void SomeipPlugin::init()
{
}

void SomeipPlugin::uninit()
{
}

std::pair<int, std::string> SomeipPlugin::command(const std::string &cmd)
{
    spdlog::info("SomeipPlugin command: {}", cmd);
    return {0, "succeed"};
}
