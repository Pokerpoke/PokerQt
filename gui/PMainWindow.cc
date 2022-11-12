#include "PMainWindow.h"
#include "base/Logger.h"
#include "gui/PTitleBar.h"
#include "ui_PMainWindow.h"
#include "HelperFunctions.h"
#include <base/Logger.h>
#include <qcursor.h>
#include <QtGui/QMouseEvent>
#include <qpoint.h>
#include "PTitleBar.h"
#include "PStatusBar.h"

using namespace Poker;

PMainWindow::PMainWindow(QWidget *parent) : QWidget(parent), ui(new Ui::PMainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);

    this->setStyleSheet(loadCss("PMainWindow.css"));

    init();
}

PMainWindow::~PMainWindow()
{
    delete ui;
}

void PMainWindow::on_close_clicked()
{
    this->close();
}

void PMainWindow::init()
{
    // auto t = new PTitleBar(this);
    // auto lay_out = this->layout();
    // lay_out->addWidget(w);

    // ui->close->setIcon(QIcon(imgPath("close.svg")));
    // ui->icon->setIcon(QIcon(imgPath("poker.svg")));
    // ui->minimal->setIcon(QIcon(imgPath("minimal.svg")));
    // ui->maximum->setIcon(QIcon(imgPath("maximum.svg")));

    // ui->window_title->setMainWidget(this);
}

void PMainWindow::on_maximum_clicked()
{
    if (this->isMaximized())
    {
        this->showNormal();
        // ui->maximum->setIcon(QIcon(imgPath("maximum.svg")));
    }
    else
    {
        this->showMaximized();
        // ui->maximum->setIcon(QIcon(imgPath("normal.svg")));
    }
}

void PMainWindow::on_minimal_clicked()
{
    this->showMinimized();
}

void PMainWindow::on_pushButton_pressed()
{
    auto cursor_pos = QCursor::pos();
    LOG_TRACE << cursor_pos.rx();
}

const QString &PMainWindow::title() const
{
    return m_title;
}

void PMainWindow::setTitle(const QString &title)
{
    if (m_title == title)
        return;
    m_title = title;
    this->setWindowTitle(m_title);
    emit titleChanged();
}
