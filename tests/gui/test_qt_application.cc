/**
 * 
 * Copyright (c) 2021 Pokerpoke
 * 
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief    
 * 
 * Last Modified:  2021-10-07
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 * 
 */
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto widget = new QWidget;
    widget->setFixedWidth(1000);
    widget->setFixedHeight(1000);
    widget->show();

    auto w = new QPushButton(widget);
    w->show();

    return app.exec();
}