
#ifndef FTPROJECT_H
#define FTPROJECT_H

#include <QDialog>
#include <QTcpServer>
#include <QMessageBox>
#include <QTcpSocket>
#include <QtNetwork>


QT_BEGIN_NAMESPACE
namespace Ui { class FTProject; }
QT_END_NAMESPACE

class FTProject : public QDialog

{
    Q_OBJECT

public:
    FTProject(QWidget *parent = nullptr);
    ~FTProject();

private slots:
    void on_pushButtonSendFile_clicked();
    void on_pushButtonSelectFile_clicked();
    void on_ListenButton_clicked();
    void on_pushButtonStopListening_clicked();

    void on_pushButtonSelectSavePath_clicked();

private:
    void acceptConnection();
    QString getHostIpAddress();
    Ui::FTProject *ui;
    QTcpServer *server;
};

#endif // FTPROJECT_H
