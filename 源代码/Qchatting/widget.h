#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QtNetwork>
namespace Ui {
class Widget;
}
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void start(QString name,QString add);
    ~Widget();
    QString uname;
    QString touser;
private slots:
    void on_send_clicked();
    void readMessage();
    void on_listWidget_itemSelectionChanged();

    void on_showtalk_textChanged();

    void on_message_textChanged();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *client;
};

#endif // WIDGET_H
