/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2022-06-17
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

// #include <QtCore/QByteArray>
#include <QtCore/QString>

namespace Poker::base
{
    class LoggerStream
    {

    public:
        using self = LoggerStream;

        LoggerStream() {}
        ~LoggerStream() {}

        QString &string()
        {
            return m_stream;
        }

        self &operator<<(const QString &in)
        {
            m_stream.append(in);
            return *this;
        }

        self &operator<<(int in)
        {
            m_stream.append(QString::number(in));
            return *this;
        }

    private:
        QString m_stream;
    };
}