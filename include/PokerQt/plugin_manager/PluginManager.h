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
#include <string>
#include <PokerQt/plugin_manager/gui_global.h>
#include <memory>
#include <PokerQt/plugin_manager/Plugin.h>
#include <PokerQt/base/Singleton.h>

namespace Poker::plugin
{
class PluginManagerPrivate;
class PLUGIN_MANAGER_EXPORT PluginManager
{
public:
    using PluginManagerPtr = std::shared_ptr<PluginManager>;

public:
    PluginManager();
    virtual ~PluginManager();

    Plugin::PluginPtr load(const std::string &path);

    Plugin::PluginPtr get_plugin(const std::string &name);

private:
    std::unique_ptr<PluginManagerPrivate> d;
};

constexpr auto PluginManagerInstance = Poker::base::Singleton<PluginManager>::instance;

} // namespace Poker::plugin