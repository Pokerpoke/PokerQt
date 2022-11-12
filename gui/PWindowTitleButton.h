#pragma once

#include <QtWidgets/QPushButton>
#include <qwidget.h>
#include <base/Global.h>

namespace Ui
{
    class PWindowTitleButton;
}

class POKER_EXPORT PWindowTitleButton : public QPushButton
{
    Q_OBJECT

public:
    explicit PWindowTitleButton(QWidget *parent = nullptr);
    ~PWindowTitleButton();

    void setMainWidget(QWidget *w);
    QWidget *mainWidget();

protected:
    // 拖拽窗口
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    bool m_dragging = false;
    QPointF m_mouse_start_pos;
    QPoint m_window_left_point;
    QWidget *m_main_widget = nullptr;
};
