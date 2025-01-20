/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2025-01-20
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
// #include "base/LoggerConfigure.h"
#include "PokerQt/gui/PMainWindow.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <PokerQt/base/Logger.h>

// using namespace Poker::base;

int main(int argc, char *argv[])
{
    // LoggerConfigureInstance().set_level(LoggerLevel::TRACE);

    QApplication app(argc, argv);

    auto w = new PMainWindow;
    w->show();

    return app.exec();
}