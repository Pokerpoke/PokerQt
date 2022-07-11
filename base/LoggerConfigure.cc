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
#include "LoggerConfigure.h"

using namespace Poker::base;

const std::map<LoggerLevel, std::string> LoggerConfigure::m_logger_level{
    {LoggerLevel::FATAL, "FATAL"},
    {LoggerLevel::ERROR, "ERROR"},
    {LoggerLevel::WARN, "WARN "},
    {LoggerLevel::INFO, "INFO "},
    {LoggerLevel::DEBUG, "DEBUG"},
    {LoggerLevel::TRACE, "TRACE"},
};

const std::map<LoggerLevel, LoggerColor> LoggerConfigure::m_logger_level_color{
    {LoggerLevel::FATAL, LoggerColor::Red},
    {LoggerLevel::ERROR, LoggerColor::Red},
    {LoggerLevel::WARN, LoggerColor::Yellow},
    {LoggerLevel::INFO, LoggerColor::Blue},
    {LoggerLevel::DEBUG, LoggerColor::White},
    {LoggerLevel::TRACE, LoggerColor::Gray},
};

const std::map<LoggerColor, std::string> LoggerConfigure::m_logger_color{
    {LoggerColor::Red, "\033[0;31m"},
    {LoggerColor::Yellow, "\033[1;33m"},
    {LoggerColor::Blue, "\033[0;34m"},
    {LoggerColor::White, "\033[1;37m"},
    {LoggerColor::Gray, "\033[1;30m"},
    {LoggerColor::Default, "\033[0m"},
};

std::string LoggerConfigure::logger_level_str(const LoggerLevel &level)
{
    return m_logger_level.at(level);
}

std::string LoggerConfigure::logger_level_color(const LoggerLevel &level)
{
    return logger_color(m_logger_level_color.at(level));
}

std::string LoggerConfigure::logger_color(const LoggerColor &color)
{
    return m_logger_color.at(color);
}
