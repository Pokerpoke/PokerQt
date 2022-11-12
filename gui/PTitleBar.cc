#include "PTitleBar.h"
#include "ui_PTitleBar.h"

PTitleBar::PTitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PTitleBar)
{
    ui->setupUi(this);
}

PTitleBar::~PTitleBar()
{
    delete ui;
}
