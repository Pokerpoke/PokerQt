#pragma once

#include <QWidget>
#include <base/Global.h>

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

private:
    Ui::PTitleBar *ui;
};
