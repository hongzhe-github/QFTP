
#ifndef MYHELPER_H
#define MYHELPER_H


#include <QObject>
#include <QFileDialog>
#include <QtCore>
#include <QtNetwork>

class myHelper : public QObject
{
    Q_OBJECT
public:
    explicit myHelper(QObject *parent = nullptr);

signals:

public:
    // 校验IP地址
    static bool IsVaild_IP(QString strIP)
    {
        QRegularExpression rx2("(\\d+)(\\.)(\\d+)(\\.)(\\d+)(\\.)(\\d+)");
        if (!rx2.match(strIP).hasMatch())
        {
            return false;
        }
        else
        {
            QStringList list = strIP.split(".");
            for (int i = 0; i < list.count(); i++)
            {
                if (list.at(i).toInt() > 255)
                {
                    return false;
                }
            }
        }
        return true;
    }

    // 获取选择文件
    static QString GetFileName(QString filter)
    {
        return QFileDialog::getOpenFileName(0,"选择文件",QCoreApplication::applicationDirPath(),filter);
    }

    // 获取IPV4地址
    static QString getHostIpAddress()
    {
        QString strIpAddress;
        QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
        // 获取第一个本主机的IPv4地址
        for (auto ipAddress : ipAddressesList) {
            if (ipAddress.protocol() == QAbstractSocket::IPv4Protocol &&
                !ipAddress.isLoopback()) {
                strIpAddress = ipAddress.toString();
                break;
            }
        }
        // 如果没有找到，则以本地IP地址为IP
        if (strIpAddress.isEmpty())
            strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
        return strIpAddress;
    }
};

#endif // MYHELPER_H
