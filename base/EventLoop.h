/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2022-11-26
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <map>
#include <base/Event.h>

namespace Poker::base
{
    class EventLoop
    {
    public:
        EventLoop()
        {
        }
        ~EventLoop() {}

        void start();
        void stop();

        void put(const Event &event);

        Event take();

        void subscribe(int event_id);
        void unsubscribe(int event_id);

    private:
        // event_id, subscriber
        std::map<int, Event> m_subscribers;
    };
}