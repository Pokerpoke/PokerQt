/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-11
 * @brief
 *
 * Last Modified:  2025-01-20
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#pragma once

#include <QtWidgets/QPushButton>
#include <PokerQt/gui/gui_global.h>

class QMouseEvent;

class POKERQT_GUI_EXPORT PPushButton : public QPushButton
{
    Q_OBJECT

public:
    explicit PPushButton(QWidget *parent = nullptr);
    ~PPushButton();

    void mouseDoubleClickEvent(QMouseEvent *event) override;

signals:
    void doubleClicked();
};
