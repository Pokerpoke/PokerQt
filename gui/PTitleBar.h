#pragma once

#include <QWidget>
#include <base/Global.h>
#include <QtGui/QIcon>
#include <qicon.h>
#include <qwidget.h>

namespace Ui
{
    class PTitleBar;
}

class POKER_EXPORT PTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit PTitleBar(QWidget *parent = nullptr);
    ~PTitleBar();

    void setIcon(const QIcon &icon);

    QIcon icon();

private slots:
    void on_close_clicked();

    void on_maximum_clicked();

    void on_minimal_clicked();

private:
    void init();

private:
    Ui::PTitleBar *ui;

    bool m_maximum = false;
};
