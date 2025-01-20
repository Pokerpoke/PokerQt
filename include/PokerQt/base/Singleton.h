/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2025-01-20
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <PokerQt/base/base_global.h>
#include <PokerQt/base/noncopyable.h>

#ifdef WIN32
#if defined(USE_SINGLETON_TEMPLATE)
#define _SINGLETON_TEMPLATE_EXPORT __declspec(dllexport)
#else
#define _SINGLETON_TEMPLATE_EXPORT __declspec(dllimport)
#endif
#else
#define _SINGLETON_TEMPLATE_EXPORT
#endif // WIN32

namespace Poker::base
{
template <typename T>
class _SINGLETON_TEMPLATE_EXPORT Singleton : noncopyable
{
public:
    static T &instance()
    {
        static T t;
        return t;
    }
};
} // namespace Poker::base