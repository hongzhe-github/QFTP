#include "ftproject.h"
#include "ui_ftproject.h"
#include "myhelper.h"

FTProject::FTProject(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FTProject)
{
    ui->setupUi(this);
}

FTProject::~FTProject()
{
    delete ui;
}

// 开始发送按钮
void FTProject::on_pushButtonSendFile_clicked()
{
    // 获取文件名和路径
    QString filePath = ui->lineEditSendFile->text();
    QFileInfo fileInfo(filePath);
    QString fileName = fileInfo.fileName();
    // 获取IP和端口
    QString ip =  ui->lineEditClinetIP->text();
    int port = ui->spinBoxClientPort->value();

    // 检查文件是否存在
    if(!fileInfo.exists())
    {
        QMessageBox::critical(this, "Error", "File does not exist");
        return;
    }
    // 校验IP合法性
    bool ip_is_valid = myHelper::IsVaild_IP(ip);

    if(!ip_is_valid)
    {
        QMessageBox::critical(this, "Error", "非法的IP地址！");
        return;
    }



    // 创建套接字并连接到目标主机
    QTcpSocket *socket = new QTcpSocket(this);
    socket->connectToHost(ip, port);

    // 等待连接成功
    if(!socket->waitForConnected(5000))
    {
        QMessageBox::critical(this, "Error", "Could not connect to host");
        return;
    }

    // 发送文件名和文件大小
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);
    out << qint64(0) << qint64(0) << fileName << qint64(fileInfo.size());

    // 计算发送的数据大小
    qint64 totalBytes = data.size() + fileInfo.size();
    qint64 bytesWritten = 0;
    ui->progressBarSendProgress->setMaximum(totalBytes);
    ui->progressBarSendProgress->setValue(bytesWritten);

    // 发送数据
    socket->write(data);
    bytesWritten += data.size();

    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, "Error", "Could not open file");
        return;
    }

    qint64 bytesToWrite = fileInfo.size();
    qint64 bytesWrittenFromFile = 0;
    while(bytesToWrite > 0)
    {
        QByteArray buffer = file.read(qMin(bytesToWrite, qint64(8192)));
        bytesWrittenFromFile = socket->write(buffer);
        bytesWritten += bytesWrittenFromFile;
        bytesToWrite -= bytesWrittenFromFile;
        ui->progressBarSendProgress->setValue(bytesWritten);
    }

    file.close();

    // 等待数据发送完成
    socket->waitForBytesWritten(5000);

    // 关闭套接字
    socket->close();
    socket->deleteLater();
    QMessageBox::information(this, "阿狸文件工具", "文件已经成功发送！",QMessageBox::Ok);
    return;
}

// 选择文件
void FTProject::on_pushButtonSelectFile_clicked()
{
    QString strFilter = "所有文件(*.*)";
    ui->lineEditSendFile->setText(myHelper::GetFileName(strFilter));
}

// 开始监听按钮
void FTProject::on_ListenButton_clicked()
{
    // 判断保存文件路径是否存在
    QFileInfo fileInfo(ui->lineEditSavePath->text());
    if(!fileInfo.exists())
    {
        QMessageBox::critical(this, "错误", "未正确选择保存路径！");
        return;
    }

    // 创建服务器并开始监听
    server = new QTcpServer(this);
    if(!server->listen(QHostAddress::Any, ui->spinBoxServerPort->value()))
    {
        QMessageBox::critical(this, "Error", "Could not start server");
        return;
    }

    // 连接新连接的信号槽
    connect(server, &QTcpServer::newConnection, this, &FTProject::acceptConnection);

    // 获取服务器地址并将其显示在lineEditReceiverIP组件中
    QString IpAddress = myHelper::getHostIpAddress();

    // 更新状态信息
    ui->lineEditReceiverIP->setText(IpAddress);

    // 更新界面状态
    ui->ListenButton->setEnabled(false);
    ui->lineEditReceiveStatus->setText("正在监听...");
}




// 接收文件函数
void FTProject::acceptConnection()
{
    // 获取已连接的套接字
    QTcpSocket *socket = server->nextPendingConnection();

    // 读取文件名和文件大小
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_3);

    qint64 bytesReceived = 0;
    qint64 fileNameSize = 0;
    QString fileName;
    qint64 fileSize = 0;

    if (socket->waitForReadyRead())
    {

        // 计算接收进度并更新进度条
        double receiveProgress = (double)bytesReceived / (double)fileSize;
        ui->progressBarReceiveProgress->setValue(receiveProgress * 100);
        in >> bytesReceived >> fileNameSize >> fileName >> fileSize;
    }

    // 打开本地文件用于接收数据
    QString saveFilePath = ui->lineEditSavePath->text() + "/" + fileName;

    QFile file(saveFilePath);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, "Error", "Could not open file");
        return;
    }


    // 接收文件
    QByteArray buffer;
    while (bytesReceived < fileSize)
    {
        if (socket->bytesAvailable() > 0) {
            buffer = socket->read(qMin(socket->bytesAvailable(), (qint64)8192));
            bytesReceived += buffer.size();
            file.write(buffer);
            // 计算接收进度并更新进度条
            double receiveProgress = (double)bytesReceived / (double)fileSize;
            ui->progressBarReceiveProgress->setValue(receiveProgress * 100);
        } else {
            socket->waitForReadyRead(100);
        }
    }


    // 关闭文件和套接字
    file.close();
    socket->close();
    socket->deleteLater();
}


// 停止监听按钮
void FTProject::on_pushButtonStopListening_clicked()
{
    // 停止监听
    server->close();

    // 更新界面状态
    ui->ListenButton->setEnabled(true);
    ui->ListenButton->setText("开始监听");
    ui->lineEditReceiveStatus->setText("未开启监听");
}

// 选择文件夹路径
void FTProject::on_pushButtonSelectSavePath_clicked()
{
    // 显示选择路径的line Edit控件(objectName:lineEditSavePath)
    QString saveDirPath = QFileDialog::getExistingDirectory(this, "选择保存文件的路径");
    ui->lineEditSavePath->setText(saveDirPath);
}

