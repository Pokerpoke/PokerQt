#include "PWindowTitleButton.h"
#include <QtGui/QMouseEvent>
#include <qwidget.h>

PWindowTitleButton::PWindowTitleButton(QWidget *parent) : QPushButton(parent)
{
}

PWindowTitleButton::~PWindowTitleButton()
{
}

void PWindowTitleButton::setMainWidget(QWidget *w)
{
    m_main_widget = w;
}

QWidget *PWindowTitleButton::mainWidget()
{
    return m_main_widget;
}

void PWindowTitleButton::mousePressEvent(QMouseEvent *event)
{
    if (!m_main_widget)
        return;
    if (event->button() == Qt::LeftButton)
    {
        m_dragging = true;
        // 获得鼠标的初始位置
        m_mouse_start_pos = event->globalPosition();
        // mouseStartPoint = event->pos();
        // 获得窗口的初始位置
        m_window_left_point = m_main_widget->frameGeometry().topLeft();
    }
}

void PWindowTitleButton::mouseMoveEvent(QMouseEvent *event)
{
    if (!m_main_widget)
        return;
    if (m_dragging)
    {
        // 获得鼠标移动的距离
        auto distance = event->globalPosition() - m_mouse_start_pos;
        // QPoint distance = event->pos() - mouseStartPoint;
        // 改变窗口的位置

        auto p = m_window_left_point + QPointF(distance);
        m_main_widget->move(p.x(), p.y());
    }
}

void PWindowTitleButton::mouseReleaseEvent(QMouseEvent *event)
{
    if (!m_main_widget)
        return;
    if (event->button() == Qt::LeftButton)
    {
        m_dragging = false;
    }
}