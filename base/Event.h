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

#include <any>

namespace Poker::base
{
    class Event
    {
    public:
        Event() {}
        ~Event() {}

        int id();

        void set_id(int id);

        void setData(const std::any &data);

        std::any data();

    private:
        int m_id = 0;
        std::any m_data;
    };
}