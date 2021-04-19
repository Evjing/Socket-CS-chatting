#include "myregister.h"
#include "ui_myregister.h"

myRegister::myRegister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myRegister)
{
    //qss样式表导入
    ui->setupUi(this);
    QFile file("./qss/mystyle.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(styleSheet);
    file.close();


    this->setWindowTitle("QQ");
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    this->setWindowOpacity(0.9);//设置透明1-全体透明
    QFont myfont;
    myfont.setFamily("幼圆");
    ui->add->setFont(myfont);
    ui->regist->setFont(myfont);
    ui->address->setFont(myfont);
    ui->name->setFont(myfont);
    ui->password->setFont(myfont);
    ui->uname->setFont(myfont);
}

myRegister::~myRegister()
{
    delete ui;
}

void myRegister::on_regist_clicked()
{
    QString myname,add;
    myname= ui->name->text();
    add=ui->address->text();
    if(add.isEmpty())
    {
        add="127.0.0.1";
    }
    w.start(myname,add);
    w.show();
    this->close();
}

void myRegister::on_pushButton_clicked()
{
    this->close();
}
