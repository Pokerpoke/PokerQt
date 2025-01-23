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
#include "PokerQt/plugin_manager/Plugin.h"
#include "spdlog/spdlog.h"
#include <PokerQt/plugin_manager/PluginManager.h>
#include <boost/dll/import.hpp>
#include <memory>
#include <unordered_map>
#include <PokerQt/base/logger.h>

namespace
{
template <class SharedPointer>
struct Holder
{
    SharedPointer p;

    Holder(const SharedPointer &p) : p(p)
    {
    }
    Holder(const Holder &other) : p(other.p)
    {
    }
    Holder(Holder &&other) : p(std::move(other.p))
    {
    }

    void operator()(...)
    {
        p.reset();
    }
};

template <class T>
std::shared_ptr<T> to_std_ptr(const boost::shared_ptr<T> &p)
{
    typedef Holder<std::shared_ptr<T>> H;
    if (H *h = boost::get_deleter<H>(p))
    {
        return h->p;
    }
    else
    {
        return std::shared_ptr<T>(p.get(), Holder<boost::shared_ptr<T>>(p));
    }
}

template <class T>
boost::shared_ptr<T> to_boost_ptr(const std::shared_ptr<T> &p)
{
    typedef Holder<boost::shared_ptr<T>> H;
    if (H *h = std::get_deleter<H>(p))
    {
        return h->p;
    }
    else
    {
        return boost::shared_ptr<T>(p.get(), Holder<std::shared_ptr<T>>(p));
    }
}
} // namespace

namespace Poker::plugin
{
class PluginManagerPrivate
{
public:
    PluginManagerPrivate()
    {
    }
    ~PluginManagerPrivate()
    {
    }

    std::unordered_map<std::string, Plugin::PluginPtr> plugins;
};

PluginManager::PluginManager()
{
    d = std::make_unique<PluginManagerPrivate>();
}

PluginManager::~PluginManager()
{
}

Plugin::PluginPtr PluginManager::load(const std::string &path)
{
    namespace dll = boost::dll;

    try
    {
        auto p =
            dll::import_symbol<Plugin>( // type of imported symbol is located between `<` and `>`
                path,                   // path to the library and library name
                "plugin",               // name of the symbol to import
                dll::load_mode::append_decorations // makes `libmy_plugin_sum.so` or
                                                   // `my_plugin_sum.dll` from `my_plugin_sum`
            );

        auto shared_p    = to_std_ptr(p);
        auto plugin_name = shared_p->name();

        auto it = d->plugins.find(plugin_name);
        if (it != d->plugins.end())
        {
            spdlog::warn("Plugin {} already loaded!", plugin_name);
            return it->second;
        }

        d->plugins.insert({shared_p->name(), shared_p});

        spdlog::info("Load plugin {} success!", shared_p->name());

        return shared_p;
    }
    catch (const std::exception &e)
    {
        spdlog::error("load plugin failed: {}", e.what());
        return nullptr;
    }
}

Plugin::PluginPtr PluginManager::get_plugin(const std::string &name)
{
    auto it = d->plugins.find(name);
    if (it != d->plugins.end())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}
} // namespace Poker::plugin