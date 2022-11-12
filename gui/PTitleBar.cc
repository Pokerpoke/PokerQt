#include "PTitleBar.h"
#include "ui_PTitleBar.h"
#include <qicon.h>
#include <gui/HelperFunctions.h>
#include <base/Logger.h>

using namespace Poker;

PTitleBar::PTitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PTitleBar)
{
    ui->setupUi(this);

    init();
}

PTitleBar::~PTitleBar()
{
    delete ui;
}

void PTitleBar::init()
{
    ui->close->setIcon(QIcon(imgPath("close.svg")));
    ui->maximum->setIcon(QIcon(imgPath("maximum.svg")));
    ui->minimal->setIcon(QIcon(imgPath("minimal.svg")));
    ui->icon->setIcon(QIcon(imgPath("Poker.svg")));

    auto parent = this->parentWidget();
    if (!parent)
        return;

    ui->window_title->setMainWidget(parent);
    // connections
    connect(ui->window_title, &PWindowTitleButton::doubleClicked, [this] { on_maximum_clicked(); });
}

void PTitleBar::on_close_clicked()
{
    auto w = this->parentWidget();
    if (!w)
        return;
    w->close();
}

void PTitleBar::on_maximum_clicked()
{
    auto w = this->parentWidget();
    if (!w)
        return;
    if (w->isMaximized())
    {
        w->showNormal();
        ui->maximum->setIcon(QIcon(imgPath("maximum.svg")));
    }
    else
    {
        w->showMaximized();
        ui->maximum->setIcon(QIcon(imgPath("normal.svg")));
    }
}

void PTitleBar::on_minimal_clicked()
{
    auto w = this->parentWidget();
    if (!w)
        return;

    w->showMinimized();
}
