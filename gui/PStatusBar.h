#pragma once

#include <QWidget>
#include <base/Global.h>
#include <chrono>

namespace Ui
{
    class PStatusBar;
}

class POKER_EXPORT PStatusBar : public QWidget
{
    Q_OBJECT

public:
    explicit PStatusBar(QWidget *parent = nullptr);
    ~PStatusBar();

public slots:
    void showMessage(const QString &msg, int duration = 2000 /* ms */);

private:
    Ui::PStatusBar *ui;
};
