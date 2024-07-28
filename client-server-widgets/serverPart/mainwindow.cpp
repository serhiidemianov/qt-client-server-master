#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>
#include <QFile>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    server = new ServerStuff(this);
    connect(server, &ServerStuff::gotNewMesssage,
            this, &MainWindow::gotNewMesssage);
    connect(server->tcpServer, &QTcpServer::newConnection,
            this, &MainWindow::smbConnectedToServer);
    connect(server, &ServerStuff::smbDisconnected,
            this, &MainWindow::smbDisconnectedFromServer);

    init();
}

MainWindow::~MainWindow()
{
    delete server;
    delete ui;
}

void MainWindow::init()
{
    // Loop to create 6 rows
    for (int i = 0; i < 6; ++i)
    {
        // Create horizontal layout for the current row
        QHBoxLayout *hLayout = new QHBoxLayout();

        // Create the label, label, label, button4
        QLabel *label1 = new QLabel(QString("Room #"));
        QLabel *label2 = new QLabel(QString("Task #"));
        QLabel *label3 = new QLabel(QString("red"));
        QButtonGroup *buttonGroup = new QButtonGroup(this);
        QPushButton *button1 = new QPushButton("Ready");
        QPushButton *button2 = new QPushButton("Start");
        QPushButton *button3 = new QPushButton("Completed");
        QPushButton *button4 = new QPushButton("Help");
        QPushButton *button5 = new QPushButton("Clear");

        // set style
        label1->setStyleSheet("QLabel {border: 1px solid black;}");
        label2->setStyleSheet("QLabel {border: 1px solid black;}");
        label1->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        label2->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        button1->setCheckable(true);
        button2->setCheckable(true);
        button3->setCheckable(true);
        button4->setCheckable(true);

        buttonGroup->addButton(button1);
        buttonGroup->addButton(button2);
        buttonGroup->addButton(button3);
        buttonGroup->addButton(button4);
        buttonGroup->setExclusive(true);
        button1->setChecked(true);

        // setProperties
        label1->setProperty("data", i);
        label2->setProperty("data", i);
        label3->setProperty("data", i);
        button1->setProperty("data", i);
        button2->setProperty("data", i);
        button3->setProperty("data", i);
        button4->setProperty("data", i);
        button5->setProperty("data", i);

        // connect slot
        connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onBtnStatusClicked(QAbstractButton*)));
        connect(button5, SIGNAL(clicked()), this, SLOT(onBtnClearClicked()));

        // Add the widgets to the horizontal layout
        hLayout->addWidget(label1);
        hLayout->addWidget(label2);
        hLayout->addWidget(label3);
        hLayout->addWidget(button1);
        hLayout->addWidget(button2);
        hLayout->addWidget(button3);
        hLayout->addWidget(button4);
        hLayout->addWidget(button5);

        // set stretch factor
        hLayout->setStretchFactor(label1, 20);
        hLayout->setStretchFactor(label2, 20);
        hLayout->setStretchFactor(label3, 1);
        hLayout->setStretchFactor(button1, 10);
        hLayout->setStretchFactor(button2, 10);
        hLayout->setStretchFactor(button3, 10);
        hLayout->setStretchFactor(button4, 10);
        hLayout->setSizeConstraint(QLayout::SetMaximumSize);
        button1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        button2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        button3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        button4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        button5->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

        // Add the horizontal layout to the main vertical layout
        ui->layoutTaskSelector->addLayout(hLayout);

    }
}

void MainWindow::on_pushButton_startServer_clicked()
{
    if (!server->tcpServer->listen(QHostAddress::Any, 6547))
    {
        ui->textEdit_log->append(tr("<font color=\"red\"><b>Error!</b> The port is taken by some other service.</font>"));
        return;
    }
    connect(server->tcpServer, &QTcpServer::newConnection, server, &ServerStuff::newConnection);
    ui->textEdit_log->append(tr("<font color=\"green\"><b>Server started</b>, port is openned.</font>"));
}

void MainWindow::on_pushButton_stopServer_clicked()
{
    if(server->tcpServer->isListening())
    {
        disconnect(server->tcpServer, &QTcpServer::newConnection, server, &ServerStuff::newConnection);

        QList<QTcpSocket *> clients = server->getClients();
        for(int i = 0; i < clients.count(); i++)
        {
            //server->sendToClient(clients.at(i), "Connection closed");
            server->sendToClient(clients.at(i), "0");
        }

        server->tcpServer->close();
        ui->textEdit_log->append(tr("<b>Server stopped</b>, post is closed"));
    }
    else
    {
        ui->textEdit_log->append(tr("<b>Error!</b> Server was not running"));
    }
}

void MainWindow::on_pushButton_testConn_clicked()
{
    if(server->tcpServer->isListening())
    {
        ui->textEdit_log->append(
                    QString("%1 %2")
                    .arg("Server is listening, number of connected clients:")
                    .arg(QString::number(server->getClients().count()))
                    );

        logMessage("[connect] Succeed");
    }
    else
    {
        ui->textEdit_log->append(
                    QString("%1 %2")
                    .arg("Server is not listening, number of connected clients:")
                    .arg(QString::number(server->getClients().count()))
                    );
        logMessage("[disconnect] Succeed");
    }
}

void MainWindow::smbConnectedToServer()
{
    ui->textEdit_log->append(tr("Somebody has connected"));
}

void MainWindow::smbDisconnectedFromServer()
{
    ui->textEdit_log->append(tr("Somebody has disconnected"));
}

void MainWindow::gotNewMesssage(QString msg)
{
    if(msg.startsWith("[GO]")) {
        // get new [GO] message
        msg.remove("[GO]");
        QStringList params = msg.split("#");
        QVariant data = params[2];
        QString room = params[0];
        QString task = params[1];

        QHBoxLayout *hLayout = (QHBoxLayout*)ui->layoutTaskSelector->children().at(data.toInt());

        QLabel *roomLabel = qobject_cast<QLabel*>(hLayout->itemAt(0)->widget());
        QLabel *taskLabel = qobject_cast<QLabel*>(hLayout->itemAt(1)->widget());
        QLabel *statusLabel = qobject_cast<QLabel*>(hLayout->itemAt(2)->widget());

        roomLabel->setText(room);
        taskLabel->setText(task);
        statusLabel->setText("Go");
    } else if(msg.startsWith("[CLEAR]")) {
        QString id = msg.remove("[CLEAR]");
        QHBoxLayout *hLayout = (QHBoxLayout*)ui->layoutTaskSelector->children().at(id.toInt());
        QLabel *label1 = qobject_cast<QLabel*>(hLayout->itemAt(0)->widget());
        QLabel *label2 = qobject_cast<QLabel*>(hLayout->itemAt(1)->widget());
        QLabel *label3 = qobject_cast<QLabel*>(hLayout->itemAt(2)->widget());
        QPushButton *button1 = qobject_cast<QPushButton*>(hLayout->itemAt(3)->widget());

        label1->setText("Room #");
        label2->setText("Task #");
        label3->setText("red");
        button1->setChecked(true);
    } else {
        ui->textEdit_log->append(QString("New message: %1").arg(msg));
    }

    // log message
    logMessage("[msg-receive]"+msg);
}

void MainWindow::onBtnStatusClicked(QAbstractButton*btn)
{
    QString status = btn->text();
    QVariant data = btn->property("data");

    QHBoxLayout *hLayout = (QHBoxLayout*)ui->layoutTaskSelector->children().at(data.toInt());
    QLabel *label1 = qobject_cast<QLabel*>(hLayout->itemAt(0)->widget());
    QLabel *label2 = qobject_cast<QLabel*>(hLayout->itemAt(1)->widget());

    if (label1->text() == "Room #" || label2->text() == "Task #")
        return;

    if(server->tcpServer->isListening())
    {
        QList<QTcpSocket *> clients = server->getClients();
        for(int i = 0; i < clients.count(); i++)
        {
            server->sendToClient(clients.at(i), QString("[STATUS]%1#%2").arg(status).arg(data.toInt()));
        }

        // log message
        QString message = QString("[status_changed] line:'%1' new_status:'%2'")
                .arg(data.toInt())
                .arg(status);
        logMessage(message);
    }
    else
    {
        ui->textEdit_log->append(tr("<b>Error!</b> Server was not running"));
    }
}

void MainWindow::onBtnClearClicked()
{
    QVariant data = this->sender()->property("data");
    QHBoxLayout *hLayout = (QHBoxLayout*)ui->layoutTaskSelector->children().at(data.toInt());
    QLabel *label1 = qobject_cast<QLabel*>(hLayout->itemAt(0)->widget());
    QLabel *label2 = qobject_cast<QLabel*>(hLayout->itemAt(1)->widget());
    QLabel *label3 = qobject_cast<QLabel*>(hLayout->itemAt(2)->widget());
    QPushButton *button1 = qobject_cast<QPushButton*>(hLayout->itemAt(3)->widget());

    qDebug() << button1->parentWidget();
    QButtonGroup *btnGroup = qobject_cast<QButtonGroup*>(button1->parentWidget());

    // log message
    QString message = QString("[clear] room:'%1' task:'%2' last_status:'%3'")
            .arg(label1->text())
            .arg(label2->text())
            .arg(button1->text());
    logMessage(message);

    // clear setting
    label1->setText("Room #");
    label2->setText("Task #");
    label3->setText("red");
    button1->setChecked(true);

    // send clear message to client
    if(server->tcpServer->isListening())
    {
        QList<QTcpSocket *> clients = server->getClients();
        for(int i = 0; i < clients.count(); i++)
        {
            server->sendToClient(clients.at(i), "[CLEAR]" + data.toInt());
        }
    }
    else
    {
        ui->textEdit_log->append(tr("<b>Error!</b> Server was not running"));
    }
}

void MainWindow::on_pushButton_sendURL_clicked()
{
    if(server->tcpServer->isListening())
    {
        QList<QTcpSocket *> clients = server->getClients();
        for(int i = 0; i < clients.count(); i++)
        {
            server->sendToClient(clients.at(i), "[URL]" + ui->lineEdit_URL->text());
        }

        // log message
        QString message = QString("[send-url] url:'%1'").arg(ui->lineEdit_URL->text());
        logMessage(message);

    }
    else
    {
        ui->textEdit_log->append(tr("<b>Error!</b> Server was not running"));
    }
}

void MainWindow::logMessage(QString message) {
    QFile file(LOG_FILE_NAME); // Name your log file

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qWarning() << "Could not open log file for writing";
        return;
    }

    QTextStream out(&file);
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    out << timestamp << " - " << message << "\n";
    file.close();
}
