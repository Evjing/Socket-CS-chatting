#include "qchat.h"
#include "ui_qchat.h"

Qchat::Qchat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qchat)
{
    ui->setupUi(this);
    QFile file("./qss/mystyle.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(styleSheet);
    file.close();
    this->setWindowTitle("QQ");
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    this->setWindowOpacity(0.9);//设置透明1-全体透明
    this->setGeometry(10,10,this->width(),this->height());
    QFont myfont;
    myfont.setFamily("幼圆");
    myfont.setPointSize(12);
    ui->show->setFont(myfont);

    //TCP监听
    server=new QTcpServer();
    server->listen(QHostAddress::Any,2000);
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

Qchat::~Qchat()
{
    delete ui;
}
//监听连接
void Qchat::acceptConnection()
{
    OnUser *on=new OnUser;
    //接受新的连接
    on->socket= server->nextPendingConnection();
    on->socket->waitForReadyRead(150);
    //读取上线信息
    QByteArray dataread = on->socket->readAll();
    QString str = QString::fromLocal8Bit(dataread);
    ui->show->append(str+"上线!");
    on->uname=str;
    //发送之前各用户的名字
    for(int i = 0;i < online->length();i ++)
       {
           QString message=(QString)"online"+"|"+online->at(i)->uname+"|";
           on->socket->write(message.toLocal8Bit());
           on->socket->waitForReadyRead(50);
       }
    //将socket加入列表
    online->append(on);
    //发送自己的名字
    for(int i = 0;i < online->length();i ++)
       {
           QString message=(QString)"online"+"|"+str+"|";
            online->at(i)->socket->write(message.toLocal8Bit());
       }
    ui->show->append("已发送上线消息");
    //收到消息反应
    connect(on->socket, SIGNAL(readyRead()), this, SLOT(readClient()));
}
void Qchat::readClient()
{
    qDebug() << online->length();
    //转发消息
    for(int i = 0;i < online->length();i ++)
       {
           qDebug() << "QDataStream " ;
           QByteArray message=online->at(i)->socket->readAll();
           if(!message.isEmpty()){
               qDebug() << "break " ;
               sendMessage(message);
               break;
           }
        }
}
//发送信息
void Qchat::sendMessage(QByteArray infomation)
{
     QString str = QString::fromLocal8Bit(infomation);
     QStringList info = str.split("|");
    ui->show->append("已转发消息");
    for (int i = 0;i < online->length();i ++)
    {
        if(online->at(i)->uname==info[2]){
        online->at(i)->socket->write(str.toLocal8Bit());
        break;
        }
    }
}


void Qchat::on_show_textChanged()
{
    ui->show->moveCursor(QTextCursor::End);
}

void Qchat::on_pushButton_clicked()
{
    this->close();
}
