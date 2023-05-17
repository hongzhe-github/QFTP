
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
    explicit myHelper(QObject* parent = nullptr);

signals:

public:
    bool IsVaild_IP(QString strIP);
    QString GetFileName(QString filter);
    QString getHostIpAddress();
};

#endif // MYHELPER_H
