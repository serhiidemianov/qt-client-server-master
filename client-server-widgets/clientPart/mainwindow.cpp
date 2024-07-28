#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVariant>
#include <QFile>
#include <QDateTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_disconnect->setVisible(false);

    client = new ClientStuff("localhost", 6547);

    setStatus(client->getStatus());

    connect(client, &ClientStuff::hasReadSome, this, &MainWindow::receivedSomething);
    connect(client, &ClientStuff::statusChanged, this, &MainWindow::setStatus);
    // FIXME change this connection to the new syntax
    connect(client->tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(gotError(QAbstractSocket::SocketError)));

    // init program
    init();
}

MainWindow::~MainWindow()
{
    delete client;
    delete ui;
}

void MainWindow::init()
{
    // initialize controls
    QTableWidgetItem *item;
    m_rooms << "In station" << "Room 1" << "Room 2" << "Room 3" << "Room 4" << "Room 5" << "Room 6" << "Room 7" << "Room 8";
    ui->tblRooms->verticalHeader()->setVisible(false);
    for(int i=0; i<m_rooms.length(); i++) {
        item = new QTableWidgetItem(m_rooms[i]);
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        int row = ui->tblRooms->rowCount();
        ui->tblRooms->insertRow(row);
        ui->tblRooms->setItem(row, 0, item);
    }

    ui->tblTasks->verticalHeader()->setVisible(false);
    ui->tblTasks->resizeColumnsToContents();

    m_tasks << "Water" << "Medication" << "Patient request" << "Supplies request" << "Lab visit" << "Check/Monitor" << "Nurse support" << "Custom";
    for(int i=0; i<m_tasks.length(); i++) {
        int row = ui->tblTasks->rowCount();
        item = new QTableWidgetItem(m_tasks[i]);
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tblTasks->insertRow(row);
        ui->tblTasks->setItem(row, 0, item);
    }

    // create and insert new tasks
    // Loop to create 6 rows
    for (int i = 0; i < 6; ++i)
    {
        // Create horizontal layout for the current row
        QHBoxLayout *hLayout = new QHBoxLayout();

        // Create the comboboxes, button and label
        QComboBox *comboBox1 = new QComboBox();
        QComboBox *comboBox2 = new QComboBox();
        QPushButton *button1 = new QPushButton("Go");
        QPushButton *button2 = new QPushButton("Clear");
        QLabel *label = new QLabel(QString("Ready"));

        // feed data to components
        comboBox1->addItem("Room #");
        comboBox2->addItem("Task #");
        comboBox1->addItems(m_rooms);
        comboBox2->addItems(m_tasks);

        // set style
        label->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        label->setMinimumWidth(80);

        // setProperties
        comboBox1->setProperty("data", i);
        comboBox2->setProperty("data", i);
        label->setProperty("data", i);
        button1->setProperty("data", i);
        button2->setProperty("data", i);

        // connect slot
        connect(button1, SIGNAL(clicked()), this, SLOT(onBtnGoClicked()));
        connect(button2, SIGNAL(clicked()), this, SLOT(onBtnClearClicked()));

        // Add the widgets to the horizontal layout
        hLayout->addWidget(comboBox1);
        hLayout->addWidget(comboBox2);
        hLayout->addWidget(button1);
        hLayout->addWidget(button2);
        hLayout->addWidget(label);

        // set stretch factor
        hLayout->setStretchFactor(comboBox1, 40);
        hLayout->setStretchFactor(comboBox2, 40);
        hLayout->setStretchFactor(button1, 1);
        hLayout->setStretchFactor(button2, 1);
        hLayout->setStretchFactor(label, 15);

        comboBox1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        comboBox2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        button1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        button2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

        // Add the horizontal layout to the main vertical layout
        ui->taskSelectorLayout->addLayout(hLayout);
    }

    ui->pushButton_link->setEnabled(false);
}

void MainWindow::setStatus(bool newStatus)
{
    if(newStatus)
    {
        ui->label_status->setText(
                    tr("<font color=\"green\">CONNECTED</font>"));
        ui->pushButton_connect->setVisible(false);
        ui->pushButton_disconnect->setVisible(true);

        // log message
        QString message = QString("[connect] Succeed");
        logMessage(message);
    }
    else
    {
        ui->label_status->setText(
                tr("<font color=\"red\">DISCONNECTED</font>"));
        ui->pushButton_connect->setVisible(true);
        ui->pushButton_disconnect->setVisible(false);

        // log message
        QString message = QString("[disconnect] Succeed");
        logMessage(message);
    }
}

void MainWindow::receivedSomething(QString msg)
{

    if( msg.startsWith("[URL]")) {
        ui->pushButton_link->setProperty("link",msg.remove(0, 5));
        ui->pushButton_link->setEnabled(true);
    } else if( msg.startsWith("[STATUS]")) {
        QString str = msg.remove("[STATUS]");
        QStringList params = str.split("#");
        QString status = params[0];
        QString id = params[1];

        // select label item with property of id
        QHBoxLayout *hLayout = (QHBoxLayout*)ui->taskSelectorLayout->children().at(id.toInt());
        QLabel *label = qobject_cast<QLabel*>(hLayout->itemAt(4)->widget());
        label->setText(status);
    } else if(msg.startsWith("[CLEAR]")) {
        QString id = msg.remove("[STATUS]");
        QHBoxLayout *hLayout = (QHBoxLayout*)ui->taskSelectorLayout->children().at(id.toInt());
        QComboBox *comboBox1 = qobject_cast<QComboBox*>(hLayout->itemAt(0)->widget());
        QComboBox *comboBox2 = qobject_cast<QComboBox*>(hLayout->itemAt(1)->widget());
        QLabel *label = qobject_cast<QLabel*>(hLayout->itemAt(4)->widget());

//        // log message
//        QString message = QString("[clear] line:'%1' room:'%2' task:'%3' last_status:'%4'")
//                .arg(id)
//                .arg(comboBox1->currentText())
//                .arg(comboBox2->currentText())
//                .arg(label->text());
//        logMessage(message);

        // reset
        comboBox1->setCurrentIndex(0);
        comboBox2->setCurrentIndex(0);
        label->setText("Ready");
    } else if(msg.startsWith("[GO]")) {
    } else {
        ui->textEdit_log->append(msg);
    }

    // log message
    logMessage(msg);
}

void MainWindow::gotError(QAbstractSocket::SocketError err)
{
    //qDebug() << "got error";
    QString strError = "unknown";
    switch (err)
    {
        case 0:
            strError = "Connection was refused";
            break;
        case 1:
            strError = "Remote host closed the connection";
            break;
        case 2:
            strError = "Host address was not found";
            break;
        case 5:
            strError = "Connection timed out";
            break;
        default:
            strError = "Unknown error";
    }

    ui->textEdit_log->append(strError);
}

void MainWindow::on_pushButton_connect_clicked()
{
    client->connect2host();
}

void MainWindow::on_pushButton_send_clicked()
{
    client->sendMessage(ui->lineEdit_message->text());

    // log message
    QString message = QString("[msg-send] message:'%1'")
            .arg(ui->lineEdit_message->text());
    logMessage(message);
}

void MainWindow::on_pushButton_disconnect_clicked()
{
    client->closeConnection();
}

void MainWindow::onBtnGoClicked() {
    QVariant data = this->sender()->property("data");
    QHBoxLayout *hLayout = (QHBoxLayout*)ui->taskSelectorLayout->children().at(data.toInt());

    QComboBox *comboBox1 = qobject_cast<QComboBox*>(hLayout->itemAt(0)->widget());
    QComboBox *comboBox2 = qobject_cast<QComboBox*>(hLayout->itemAt(1)->widget());
    QLabel *label = qobject_cast<QLabel*>(hLayout->itemAt(4)->widget());

    QString curStatus = label->text();

    if( curStatus == "Ready" ) {
        QString room = comboBox1->currentText();
        QString task = comboBox2->currentText();

        if (room != "Room #" && task != "Task #") {
            QString inst = QString("[GO]%1#%2#%3").arg(room).arg(task).arg(data.toInt());
            client->sendMessage(inst);

            // log message
            QString message = QString("[go] room:'%1' task:'%2' last_status:'%3'")
                    .arg(comboBox1->currentText())
                    .arg(comboBox2->currentText())
                    .arg(label->text());
            logMessage(message);
        }
    }
}

void MainWindow::onBtnClearClicked() {
    QVariant data = this->sender()->property("data");
    QHBoxLayout *hLayout = (QHBoxLayout*)ui->taskSelectorLayout->children().at(data.toInt());

    QComboBox *comboBox1 = qobject_cast<QComboBox*>(hLayout->itemAt(0)->widget());
    QComboBox *comboBox2 = qobject_cast<QComboBox*>(hLayout->itemAt(1)->widget());
    QLabel *label = qobject_cast<QLabel*>(hLayout->itemAt(4)->widget());

    // log message
    QString message = QString("[clear] room:'%1' task:'%2' last_status:'%3'")
            .arg(comboBox1->currentText())
            .arg(comboBox2->currentText())
            .arg(label->text());
    logMessage(message);

    // reset
    comboBox1->setCurrentIndex(0);
    comboBox2->setCurrentIndex(0);
    label->setText("Ready");

    // send clear message to server
    QString inst = QString("[CLEAR]%1").arg(data.toInt());
    client->sendMessage(inst);
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

void MainWindow::on_pushButton_link_clicked()
{
    QString link = ((QPushButton*)sender())->property("link").toString();

    // Specify the URL to open
    QUrl url(link);
    // Use QDesktopServices to open the URL
    QDesktopServices::openUrl(url);

    // log message
    QString message = QString("[openlink] openlink:'%1'")
            .arg(link);
    logMessage(message);
}
