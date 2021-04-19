#include "myregister.h"
#include "mt
#include <QApplication>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //打开界面窗口
    myRegister Re;
    Re.show();

    return a.exec();
}


