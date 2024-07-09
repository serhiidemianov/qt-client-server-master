#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "clientStuff.h"
#include <QStringList>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QDesktopServices>

#define LOG_FILE_NAME "nurse-client.log"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
protected:
    void init();
    void logMessage(QString msg);

public slots:
    void setStatus(bool newStatus);
    void receivedSomething(QString msg);
    void gotError(QAbstractSocket::SocketError err);

private slots:
    void on_pushButton_send_clicked();
    void on_pushButton_connect_clicked();
    void on_pushButton_disconnect_clicked();
    void onBtnGoClicked();
    void onBtnClearClicked();

    void on_pushButton_link_clicked();

private:
    Ui::MainWindow *ui;
    ClientStuff *client;

    QStringList m_rooms, m_tasks;

    QList<QComboBox*> comboBox1List;
    QList<QComboBox*> comboBox2List;
    QList<QPushButton*> buttonList;
    QList<QLabel*> labelList;
};

#endif // MAINWINDOW_H
