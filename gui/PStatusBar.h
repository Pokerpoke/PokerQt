#pragma once

#include <QWidget>
#include <base/Global.h>

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

private:
    Ui::PStatusBar *ui;
};
