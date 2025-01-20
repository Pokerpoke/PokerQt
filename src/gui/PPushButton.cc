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

#include "PPushButton.h"

PPushButton::PPushButton(QWidget *parent) : QPushButton(parent)
{
}

PPushButton::~PPushButton()
{
}

void PPushButton::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit this->doubleClicked();
}