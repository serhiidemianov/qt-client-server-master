/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *labelTitle;
    QVBoxLayout *layoutTaskSelector;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_URL;
    QPushButton *pushButton_sendURL;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_startServer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_testConn;
    QTextEdit *textEdit_log;
    QPushButton *pushButton_stopServer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(720, 475);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QLatin1String("#centralWidget {\n"
"	background-color: rgb(122, 210, 246);\n"
"}\n"
"QWidget {\n"
"	font: 13pt \"MS Shell Dlg 2\";\n"
"}\n"
"#labelTitle {\n"
"	font: Bold 30pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QAbstractButton {\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelTitle = new QLabel(centralWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelTitle, 0, 0, 1, 1);

        layoutTaskSelector = new QVBoxLayout();
        layoutTaskSelector->setSpacing(6);
        layoutTaskSelector->setObjectName(QStringLiteral("layoutTaskSelector"));
        layoutTaskSelector->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout->addLayout(layoutTaskSelector, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_URL = new QLineEdit(centralWidget);
        lineEdit_URL->setObjectName(QStringLiteral("lineEdit_URL"));
        QFont font1;
        font1.setPointSize(13);
        lineEdit_URL->setFont(font1);

        horizontalLayout_3->addWidget(lineEdit_URL);

        pushButton_sendURL = new QPushButton(centralWidget);
        pushButton_sendURL->setObjectName(QStringLiteral("pushButton_sendURL"));
        pushButton_sendURL->setFont(font1);

        horizontalLayout_3->addWidget(pushButton_sendURL);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_startServer = new QPushButton(centralWidget);
        pushButton_startServer->setObjectName(QStringLiteral("pushButton_startServer"));
        pushButton_startServer->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font2.setPointSize(13);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        pushButton_startServer->setFont(font2);
        pushButton_startServer->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));

        horizontalLayout_2->addWidget(pushButton_startServer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_testConn = new QPushButton(centralWidget);
        pushButton_testConn->setObjectName(QStringLiteral("pushButton_testConn"));
        pushButton_testConn->setFont(font1);

        horizontalLayout->addWidget(pushButton_testConn);


        horizontalLayout_2->addLayout(horizontalLayout);

        textEdit_log = new QTextEdit(centralWidget);
        textEdit_log->setObjectName(QStringLiteral("textEdit_log"));
        textEdit_log->setMaximumSize(QSize(16777215, 50));
        textEdit_log->setFont(font2);

        horizontalLayout_2->addWidget(textEdit_log);

        pushButton_stopServer = new QPushButton(centralWidget);
        pushButton_stopServer->setObjectName(QStringLiteral("pushButton_stopServer"));
        pushButton_stopServer->setEnabled(true);
        pushButton_stopServer->setFont(font2);
        pushButton_stopServer->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        pushButton_stopServer->setCheckable(false);
        pushButton_stopServer->setChecked(false);
        pushButton_stopServer->setAutoDefault(false);
        pushButton_stopServer->setFlat(false);

        horizontalLayout_2->addWidget(pushButton_stopServer);

        horizontalLayout_2->setStretch(1, 90);

        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        gridLayout->setRowStretch(1, 90);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        pushButton_stopServer->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Server", 0));
        labelTitle->setText(QApplication::translate("MainWindow", "Nurse Asistant View", 0));
        lineEdit_URL->setPlaceholderText(QApplication::translate("MainWindow", "Type here the URL you want to send", 0));
        pushButton_sendURL->setText(QApplication::translate("MainWindow", "Send", 0));
        pushButton_startServer->setText(QApplication::translate("MainWindow", "Start server", 0));
        pushButton_testConn->setText(QApplication::translate("MainWindow", "Test", 0));
        pushButton_stopServer->setText(QApplication::translate("MainWindow", "Stop server", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
