#pragma once

#include <QWidget>
#include <PokerQt/gui/gui_global.h>
#include <chrono>

namespace Ui
{
class PStatusBar;
}

class POKERQT_GUI_EXPORT PStatusBar : public QWidget
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
