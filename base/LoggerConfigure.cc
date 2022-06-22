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
#include "LoggerConfigure.h"

using namespace Poker::base;

const QMap<LoggerLevel, QString> LoggerConfigure::m_logger_level{
    {LoggerLevel::FATAL, "FATAL"},
    {LoggerLevel::ERROR, "ERROR"},
    {LoggerLevel::WARN, "WARN "},
    {LoggerLevel::INFO, "INFO "},
    {LoggerLevel::DEBUG, "DEBUG"},
    {LoggerLevel::TRACE, "TRACE"},
};

const QMap<LoggerLevel, LoggerColor> LoggerConfigure::m_logger_level_color{
    {LoggerLevel::FATAL, LoggerColor::Red},
    {LoggerLevel::ERROR, LoggerColor::Red},
    {LoggerLevel::WARN, LoggerColor::Yellow},
    {LoggerLevel::INFO, LoggerColor::Blue},
    {LoggerLevel::DEBUG, LoggerColor::White},
    {LoggerLevel::TRACE, LoggerColor::Gray},
};

const QMap<LoggerColor, QString> LoggerConfigure::m_logger_color{
    {LoggerColor::Red, "\033[0;31m"},
    {LoggerColor::Yellow, "\033[1;33m"},
    {LoggerColor::Blue, "\033[0;34m"},
    {LoggerColor::White, "\033[1;37m"},
    {LoggerColor::Gray, "\033[1;30m"},
    {LoggerColor::Default, "\033[0m"},
};

QString LoggerConfigure::logger_level_str(const LoggerLevel &level)
{
    return m_logger_level.value(level);
}

QString LoggerConfigure::logger_level_color(const LoggerLevel &level)
{
    return logger_color(m_logger_level_color.value(level));
}

QString LoggerConfigure::logger_color(const LoggerColor &color)
{
    return m_logger_color.value(color);
}
