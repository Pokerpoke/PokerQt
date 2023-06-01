/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-11-12
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include "base/LoggerConfigure.h"
#include "gui/PMainWindow.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <base/Logger.h>

using namespace Poker::base;

int main(int argc, char *argv[])
{
    LoggerConfigureInstance().set_level(LoggerLevel::TRACE);

    QApplication app(argc, argv);

    auto w = new PMainWindow;
    w->show();

    return app.exec();
}