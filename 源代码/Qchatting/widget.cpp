#include "widget.h"
#include "ui_widget.h"
#include "qdialog.h"
#include <QtNetwork>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //加载头像
    //界面初始设置
    QPixmap image;
    image.load("./picture/1.jpg");
    ui->setupUi(this);
    image=image.scaled(ui->ShowPicture->size());
    ui->ShowPicture->setPixmap(image);
    ui->ShowPicture->show();//显示
    this->setWindowTitle("QQ");
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    this->setWindowOpacity(0.9);//设置透明1-全体透明
    QFont myfont;
    myfont.setFamily("幼圆");
    myfont.setPointSize(12);
    ui->label->setFont(myfont);
    ui->showtalk->setFont(myfont);
    ui->message->setFont(myfont);
    ui->listWidget->setFont(myfont);
}

//初始设置
void Widget::start(QString name,QString add)
{
     this->uname=name;
     this->touser=name;
     //欢迎信息
     ui->label->setText(name);
     ui->showtalk->append("你好,"+uname+"!");
     //socket连接
     client = new QTcpSocket(this);
     client->connectToHost(QHostAddress(add),2000);
     //将名字传给服务器,上线
     client->waitForBytesWritten(50);
     client->write(uname.toLocal8Bit());
     connect(client,SIGNAL(readyRead()),this,SLOT(readMessage()));
}
Widget::~Widget()
{
    delete ui;
}

//发送信息
void Widget::on_send_clicked()
{
    QString message;
    ui

    //给服务器发消息,发送自己名字+对方名字+要说的话
    message =(QString)"message"+"|"+uname+ "|"+touser+"|"+ui->message->toPlainText()+"|";
    client->write(message.toLocal8Bit());
    //屏幕显示自己要说的话
    ui->showtalk->setTextColor(QColor(255,0,0));
    ui->showtalk->append(" 我 ");
    ui->showtalk->setTextColor(QColor(0,0,0));
    ui->showtalk->insertPlainText("对 ");
    ui->showtalk->setTextColor(QColor(0,0,255));
    ui->showtalk->insertPlainText(touser);
    ui->showtalk->setTextColor(QColor(0,0,0));
    ui->showtalk->insertPlainText(" 说\n");
    ui->showtalk->setTextColor(QColor(0,255,0));
    ui->showtalk->insertPlainText(ui->message->toPlainText());
    //清空屏幕
    ui->showtalk->setTextColor(QColor(0,0,0));
    ui->message->clear();

}
//接受服务端信息
void Widget::readMessage()
{
       QString check1="message";
       QString check2="online";
       QByteArray dataread=client->readAll();
       //接受信号分离
       QString str = QString::fromLocal8Bit(dataread);
       QStringList info = str.split("|");
       //根据信号类型作出反应
       if(info[0]==check1){
       ui->showtalk->setTextColor(QColor(0,0,255));
       ui->showtalk->append(" "+info[1]);
       ui->showtalk->setTextColor(QColor(0,0,0));
       ui->showtalk->insertPlainText("对 ");
       ui->showtalk->setTextColor(QColor(255,0,0));
       ui->showtalk->insertPlainText("我");
       ui->showtalk->setTextColor(QColor(0,0,0));
       ui->showtalk->insertPlainText(" 说\n");
       ui->showtalk->setTextColor(QColor(0,255,0));
       ui->showtalk->insertPlainText(info[3]);
       ui->showtalk->setTextColor(QColor(0,0,0));
       }else if(info[0]==check2)
       {
           ui->listWidget->insertItem(0,info[1]);
       }
       info.clear();//这句话必须有，不然会出现客户端崩溃的情况，超出范围
}

//改变说话对象
void Widget::on_listWidget_itemSelectionChanged()
{
   touser=ui->listWidget->currentItem()->text();
}

void Widget::on_showtalk_textChanged()
{
    ui->showtalk->moveCursor(QTextCursor::End);
}

void Widget::on_message_textChanged()
{
    ui->message->moveCursor(QTextCursor::End);
}

void Widget::on_pushButton_clicked()
{
   this->close();
}
