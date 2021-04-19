/********************************************************************************
** Form generated from reading UI file 'qchat.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCHAT_H
#define UI_QCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qchat
{
public:
    QTextEdit *show;
    QPushButton *pushButton;
    QFrame *frame;

    void setupUi(QWidget *Qchat)
    {
        if (Qchat->objectName().isEmpty())
            Qchat->setObjectName(QStringLiteral("Qchat"));
        Qchat->resize(400, 300);
        show = new QTextEdit(Qchat);
        show->setObjectName(QStringLiteral("show"));
        show->setGeometry(QRect(80, 60, 241, 201));
        pushButton = new QPushButton(Qchat);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 20, 31, 28));
        frame = new QFrame(Qchat);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-1, -1, 401, 301));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        show->raise();
        pushButton->raise();

        retranslateUi(Qchat);

        QMetaObject::connectSlotsByName(Qchat);
    } // setupUi

    void retranslateUi(QWidget *Qchat)
    {
        Qchat->setWindowTitle(QApplication::translate("Qchat", "Qchat", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Qchat", "\303\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Qchat: public Ui_Qchat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCHAT_H
