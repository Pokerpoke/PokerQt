/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2022-07-04
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#pragma once

namespace Poker::base
{
    class Event
    {
    public:
        Event() {}
        ~Event() {}

        int id()
        {
            return m_id;
        }

        void set_id(int id)
        {
            m_id = id;
        }

    private:
        int m_id;
    };
}