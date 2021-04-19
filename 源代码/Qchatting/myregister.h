#ifndef MYREGISTER_H
#define MYREGISTER_H

#include <QWidget>
#include "widget.h"
namespace Ui {
class myRegister;
}

class myRegister : public QWidget
{
    Q_OBJECT

public:
    explicit myRegister(QWidget *parent = 0);
    ~myRegister();

private slots:
    void on_regist_clicked();
    void on_pushButton_clicked();

private:
    Ui::myRegister *ui;
    Widget w;
};

#endif // MYREGISTER_H
