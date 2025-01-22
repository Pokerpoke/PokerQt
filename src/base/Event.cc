/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-11
 * @brief
 *
 * Last Modified:  2025-01-22
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include "PokerQt/base/Event.h"

using namespace Poker::base;

namespace Poker::base
{
class EventPrivate
{
public:
    EventPrivate()
    {
    }

    ~EventPrivate()
    {
    }

    int id;
    std::any data;
    Event::CallbackType callback;
};
} // namespace Poker::base

Event::Event()
{
    d = std::make_shared<EventPrivate>();
}

Event::~Event()
{
}

int Event::id()
{
    return d->id;
}

void Event::set_id(int id)
{
    d->id = id;
}

void Event::setData(const std::any &data)
{
    d->data = data;
}

std::any Event::data()
{
    return d->data;
}

Event::CallbackType Event::callback()
{
    return d->callback;
}

void Event::setCallback(Event::CallbackType callback)
{
    d->callback = callback;
}