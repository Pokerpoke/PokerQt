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

#include <boost/config.hpp>
#include <PokerQt/plugin_manager/Plugin.h>

class SomeipPlugin : public Poker::plugin::Plugin
{
public:
    SomeipPlugin();
    ~SomeipPlugin();

    std::string name() override;

    void init() override;
    void uninit() override;

    std::pair<int, std::string> command(const std::string &cmd) override;
};

extern "C" BOOST_SYMBOL_EXPORT SomeipPlugin plugin;
SomeipPlugin plugin;