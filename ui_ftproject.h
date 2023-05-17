/********************************************************************************
** Form generated from reading UI file 'ftproject.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTPROJECT_H
#define UI_FTPROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FTProject
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QProgressBar *progressBarReceiveProgress;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QLineEdit *lineEditReceiverIP;
    QLabel *label_6;
    QSpinBox *spinBoxServerPort;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLineEdit *lineEditReceiveStatus;
    QPushButton *ListenButton;
    QPushButton *pushButtonStopListening;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *lineEditSavePath;
    QPushButton *pushButtonSelectSavePath;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditClinetIP;
    QLabel *label_2;
    QSpinBox *spinBoxClientPort;
    QPushButton *pushButtonSendFile;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEditSendFile;
    QPushButton *pushButtonSelectFile;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QProgressBar *progressBarSendProgress;

    void setupUi(QDialog *FTProject)
    {
        if (FTProject->objectName().isEmpty())
            FTProject->setObjectName(QString::fromUtf8("FTProject"));
        FTProject->resize(420, 290);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/417.ico"), QSize(), QIcon::Normal, QIcon::Off);
        FTProject->setWindowIcon(icon);
        layoutWidget = new QWidget(FTProject);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 160, 381, 110));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        progressBarReceiveProgress = new QProgressBar(layoutWidget);
        progressBarReceiveProgress->setObjectName(QString::fromUtf8("progressBarReceiveProgress"));
        progressBarReceiveProgress->setValue(0);

        horizontalLayout_6->addWidget(progressBarReceiveProgress);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_5->addWidget(label_10);

        lineEditReceiverIP = new QLineEdit(layoutWidget);
        lineEditReceiverIP->setObjectName(QString::fromUtf8("lineEditReceiverIP"));
        lineEditReceiverIP->setEnabled(true);
        lineEditReceiverIP->setStyleSheet(QString::fromUtf8("background-color: palette(base); "));
        lineEditReceiverIP->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEditReceiverIP);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        spinBoxServerPort = new QSpinBox(layoutWidget);
        spinBoxServerPort->setObjectName(QString::fromUtf8("spinBoxServerPort"));
        spinBoxServerPort->setMinimum(1024);
        spinBoxServerPort->setMaximum(88888);
        spinBoxServerPort->setValue(12345);

        horizontalLayout_5->addWidget(spinBoxServerPort);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        lineEditReceiveStatus = new QLineEdit(layoutWidget);
        lineEditReceiveStatus->setObjectName(QString::fromUtf8("lineEditReceiveStatus"));
        lineEditReceiveStatus->setEnabled(false);

        horizontalLayout_7->addWidget(lineEditReceiveStatus);

        ListenButton = new QPushButton(layoutWidget);
        ListenButton->setObjectName(QString::fromUtf8("ListenButton"));

        horizontalLayout_7->addWidget(ListenButton);

        pushButtonStopListening = new QPushButton(layoutWidget);
        pushButtonStopListening->setObjectName(QString::fromUtf8("pushButtonStopListening"));

        horizontalLayout_7->addWidget(pushButtonStopListening);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        lineEditSavePath = new QLineEdit(layoutWidget);
        lineEditSavePath->setObjectName(QString::fromUtf8("lineEditSavePath"));
        lineEditSavePath->setEnabled(false);

        horizontalLayout_8->addWidget(lineEditSavePath);

        pushButtonSelectSavePath = new QPushButton(layoutWidget);
        pushButtonSelectSavePath->setObjectName(QString::fromUtf8("pushButtonSelectSavePath"));

        horizontalLayout_8->addWidget(pushButtonSelectSavePath);


        verticalLayout_3->addLayout(horizontalLayout_8);

        widget = new QWidget(FTProject);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 381, 121));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditClinetIP = new QLineEdit(widget);
        lineEditClinetIP->setObjectName(QString::fromUtf8("lineEditClinetIP"));

        horizontalLayout->addWidget(lineEditClinetIP);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBoxClientPort = new QSpinBox(widget);
        spinBoxClientPort->setObjectName(QString::fromUtf8("spinBoxClientPort"));
        spinBoxClientPort->setMinimum(1024);
        spinBoxClientPort->setMaximum(88888);
        spinBoxClientPort->setValue(12345);

        horizontalLayout->addWidget(spinBoxClientPort);

        pushButtonSendFile = new QPushButton(widget);
        pushButtonSendFile->setObjectName(QString::fromUtf8("pushButtonSendFile"));

        horizontalLayout->addWidget(pushButtonSendFile);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEditSendFile = new QLineEdit(widget);
        lineEditSendFile->setObjectName(QString::fromUtf8("lineEditSendFile"));
        lineEditSendFile->setEnabled(false);

        horizontalLayout_2->addWidget(lineEditSendFile);

        pushButtonSelectFile = new QPushButton(widget);
        pushButtonSelectFile->setObjectName(QString::fromUtf8("pushButtonSelectFile"));

        horizontalLayout_2->addWidget(pushButtonSelectFile);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        progressBarSendProgress = new QProgressBar(widget);
        progressBarSendProgress->setObjectName(QString::fromUtf8("progressBarSendProgress"));
        progressBarSendProgress->setValue(0);

        horizontalLayout_3->addWidget(progressBarSendProgress);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(FTProject);

        QMetaObject::connectSlotsByName(FTProject);
    } // setupUi

    void retranslateUi(QDialog *FTProject)
    {
        FTProject->setWindowTitle(QCoreApplication::translate("FTProject", "\351\230\277\347\213\270\347\232\204\344\274\240\350\276\223\345\267\245\345\205\267", nullptr));
        label_7->setText(QCoreApplication::translate("FTProject", "\346\216\245\346\224\266\350\277\233\345\272\246", nullptr));
        label_10->setText(QCoreApplication::translate("FTProject", "\346\216\245\346\224\266\347\253\257 IP", nullptr));
        label_6->setText(QCoreApplication::translate("FTProject", "\346\216\245\346\224\266\346\226\271\347\253\257\345\217\243", nullptr));
        label_9->setText(QCoreApplication::translate("FTProject", "\346\216\245\346\224\266\347\212\266\346\200\201", nullptr));
        lineEditReceiveStatus->setText(QCoreApplication::translate("FTProject", "\346\234\252\345\274\200\345\220\257\347\233\221\345\220\254", nullptr));
        ListenButton->setText(QCoreApplication::translate("FTProject", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
        pushButtonStopListening->setText(QCoreApplication::translate("FTProject", "\345\201\234\346\255\242\347\233\221\345\220\254", nullptr));
        label_8->setText(QCoreApplication::translate("FTProject", "\344\277\235\345\255\230\344\275\215\347\275\256", nullptr));
        pushButtonSelectSavePath->setText(QCoreApplication::translate("FTProject", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
        label->setText(QCoreApplication::translate("FTProject", "\345\217\221\351\200\201\347\253\257 IP", nullptr));
        lineEditClinetIP->setText(QCoreApplication::translate("FTProject", "127.0.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("FTProject", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        pushButtonSendFile->setText(QCoreApplication::translate("FTProject", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        label_3->setText(QCoreApplication::translate("FTProject", "\346\226\207\344\273\266\345\220\215\347\247\260", nullptr));
        pushButtonSelectFile->setText(QCoreApplication::translate("FTProject", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        label_5->setText(QCoreApplication::translate("FTProject", "\345\217\221\351\200\201\350\277\233\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
class FTProject: public Ui_FTProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTPROJECT_H
