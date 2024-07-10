#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QDebug>
#include "serverStuff.h"

namespace Ui {
class MainWindow;
}

#define LOG_FILE_NAME "nurse-server.log"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
protected:
    void init();
    void logMessage(QString msg);

private slots:
    void on_pushButton_stopServer_clicked();
    void on_pushButton_startServer_clicked();
    void on_pushButton_testConn_clicked();
    void smbConnectedToServer();
    void smbDisconnectedFromServer();
    void gotNewMesssage(QString msg);

    void onBtnStatusClicked(QAbstractButton*);
    void onBtnClearClicked();

    void on_pushButton_sendURL_clicked();

private:
    Ui::MainWindow *ui;
    ServerStuff *server;

    QList<QString> m_curStatusList;
};

#endif // MAINWINDOW_H
