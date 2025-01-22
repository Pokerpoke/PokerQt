/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2025-01-22
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#pragma once

#include <memory>
#include <any>
#include <functional>
#include <PokerQt/base/base_global.h>

namespace Poker::base
{
class EventPrivate;

class POKERQT_BASE_EXPORT Event
{
public:
    using CallbackType = std::function<void(const std::any &)>;

public:
    Event();

    ~Event();

    int id();

    void set_id(int id);

    void setData(const std::any &data);

    CallbackType callback();

    void setCallback(CallbackType callback);

    std::any data();

private:
    std::shared_ptr<EventPrivate> d;
};

} // namespace Poker::base