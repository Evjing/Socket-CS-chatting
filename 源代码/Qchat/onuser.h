#ifndef ONUSER_H
#define ONUSER_H
#include <QWidget>
#include <QtNetwork>

class OnUser: public QWidget
{
public:
    OnUser();
    QString uname;
    QTcpSocket *socket;
};

#endif // ONUSER_H
