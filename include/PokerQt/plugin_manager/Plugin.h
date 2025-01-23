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
#pragma once

#include <PokerQt/plugin_manager/gui_global.h>
#include <string>
#include <memory>

namespace Poker::plugin
{
class PLUGIN_MANAGER_EXPORT Plugin
{
public:
    using PluginPtr = std::shared_ptr<Plugin>;

public:
    Plugin();
    virtual ~Plugin();

    virtual std::string name() = 0;

    virtual void init();
    virtual void uninit();

    virtual std::pair<int, std::string> command(const std::string &cmd);
};
} // namespace Poker::plugin