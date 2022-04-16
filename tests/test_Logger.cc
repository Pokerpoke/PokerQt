/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-03
 * @brief
 *
 * Last Modified:  2022-03-26
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include "base/Logger.h"

using namespace std;
using namespace Poker::base;

int main(int argc, char const *argv[])
{
    // test log color
    LOG_DEBUG << Logger::log_color(Logger::LogColor::Black) << "Black "
              << Logger::log_color(Logger::LogColor::Red) << "Red "
              << Logger::log_color(Logger::LogColor::Green) << "Green "
              << Logger::log_color(Logger::LogColor::Yellow) << "Yellow "
              << Logger::log_color(Logger::LogColor::Blue) << "Blue "
              << Logger::log_color(Logger::LogColor::Magenta) << "Magenta "
              << Logger::log_color(Logger::LogColor::Cyan) << "Cyan "
              << Logger::log_color(Logger::LogColor::Default) << "Default ";
    //   << endl;
    return 0;
}
