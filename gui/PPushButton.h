/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-11
 * @brief
 *
 * Last Modified:  2022-11-12
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#pragma once

#include <QtWidgets/QPushButton>
#include <base/Global.h>

class QMouseEvent;

class POKER_EXPORT PPushButton : public QPushButton
{
    Q_OBJECT

public:
    explicit PPushButton(QWidget *parent = nullptr);
    ~PPushButton();

    void mouseDoubleClickEvent(QMouseEvent *event) override;

signals:
    void doubleClicked();
};
