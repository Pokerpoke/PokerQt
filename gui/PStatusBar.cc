#include "PStatusBar.h"
#include "ui_PStatusBar.h"

PStatusBar::PStatusBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PStatusBar)
{
    ui->setupUi(this);
}

PStatusBar::~PStatusBar()
{
    delete ui;
}

void PStatusBar::showMessage(const QString &msg, int duration)
{
}
