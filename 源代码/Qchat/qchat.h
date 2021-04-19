#ifndef QCHAT_H
#define QCHAT_H
#include <QtNetwork>
#include <QWidget>
#include <onuser.h>
namespace Ui {
class Qchat;
}

class Qchat : public QWidget
{
    Q_OBJECT
public:
    explicit Qchat(QWidget *parent = 0);
    ~Qchat();
     QList<OnUser*> *online=new QList<OnUser*> ;
     void sendMessage(QByteArray infomation);
private slots:
    void acceptConnection();
    void readClient();
    void on_show_textChanged();

    void on_pushButton_clicked();

private:
        Ui::Qchat *ui;
        QTcpServer *server;

};

#endif // QCHAT_H
