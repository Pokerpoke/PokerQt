/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-11
 * @brief
 *
 * Last Modified:  2022-11-26
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include "Event.h"

using namespace Poker::base;

int Event::id()
{
    return m_id;
}

void Event::set_id(int id)
{
    m_id = id;
}

void Event::setData(const std::any &data)
{
    m_data = data;
}

std::any Event::data()
{
    return m_data;
}