/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-03-26
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#include <memory>
#include <map>
#include <list>
#include <string>

#include <base/Singleton.h>
#include <base/LoggerAppenderBase.h>

namespace Poker::base
{

    class LoggerConfigure
    {
    public:
        bool colored()
        {
            return m_colored;
        }

        void set_colored(bool colored = true)
        {
            m_colored = true;
        }

        // check if global or local configure
        void set_overrided(bool in = true)
        {
            m_overrided = true;
        }

        bool overrided()
        {
            return m_overrided;
        }

    private:
        bool m_colored = false;
        bool m_overrided = false;
    };

    // global configure
    static auto LoggerConfigureGlobal = Poker::base::Singleton<Poker::base::LoggerConfigure>::instance;
}
