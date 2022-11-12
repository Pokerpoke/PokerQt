#pragma once

#include <base/Global.h>
#include <QtWidgets/QWidget>

namespace Ui
{
    class PMainWindow;
}

class POKER_EXPORT PMainWindow : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)

public:
    explicit PMainWindow(QWidget *parent = nullptr);
    ~PMainWindow();

    const QString &title() const;
    void setTitle(const QString &title);

signals:
    void titleChanged();

private:
    void init();

private:
    Ui::PMainWindow *ui;
    QString m_title;
};
