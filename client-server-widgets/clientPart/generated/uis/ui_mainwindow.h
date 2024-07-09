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
#include <QtWidgets/QTableWidget>
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
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tblRooms;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *taskSelectorLayout;
    QPushButton *pushButton_link;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_message;
    QPushButton *pushButton_send;
    QTableWidget *tblTasks;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_disconnect;
    QTextEdit *textEdit_log;
    QLabel *label_status;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(730, 454);
        MainWindow->setStyleSheet(QLatin1String("#centralWidget {\n"
"	background-color: rgb(122, 210, 246);\n"
"}\n"
"\n"
"QWidget{\n"
"	font: 13pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"#labelTitle {\n"
"font: Bold 30pt \"MS Shell Dlg 2\";\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelTitle = new QLabel(centralWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelTitle, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tblRooms = new QTableWidget(centralWidget);
        if (tblRooms->columnCount() < 1)
            tblRooms->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblRooms->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tblRooms->setObjectName(QStringLiteral("tblRooms"));
        tblRooms->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblRooms->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_3->addWidget(tblRooms);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        taskSelectorLayout = new QVBoxLayout();
        taskSelectorLayout->setSpacing(6);
        taskSelectorLayout->setObjectName(QStringLiteral("taskSelectorLayout"));

        verticalLayout->addLayout(taskSelectorLayout);

        pushButton_link = new QPushButton(centralWidget);
        pushButton_link->setObjectName(QStringLiteral("pushButton_link"));
        QFont font1;
        font1.setPointSize(13);
        pushButton_link->setFont(font1);

        verticalLayout->addWidget(pushButton_link);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_message = new QLineEdit(centralWidget);
        lineEdit_message->setObjectName(QStringLiteral("lineEdit_message"));
        lineEdit_message->setFont(font1);

        horizontalLayout->addWidget(lineEdit_message);

        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setFont(font1);

        horizontalLayout->addWidget(pushButton_send);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 90);

        horizontalLayout_3->addLayout(verticalLayout);

        tblTasks = new QTableWidget(centralWidget);
        if (tblTasks->columnCount() < 1)
            tblTasks->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblTasks->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        tblTasks->setObjectName(QStringLiteral("tblTasks"));
        tblTasks->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblTasks->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_3->addWidget(tblTasks);

        horizontalLayout_3->setStretch(0, 15);
        horizontalLayout_3->setStretch(1, 60);
        horizontalLayout_3->setStretch(2, 25);

        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_connect = new QPushButton(centralWidget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font2.setPointSize(13);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        pushButton_connect->setFont(font2);
        pushButton_connect->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));

        horizontalLayout_2->addWidget(pushButton_connect);

        pushButton_disconnect = new QPushButton(centralWidget);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));
        pushButton_disconnect->setEnabled(true);
        pushButton_disconnect->setFont(font2);
        pushButton_disconnect->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        horizontalLayout_2->addWidget(pushButton_disconnect);

        textEdit_log = new QTextEdit(centralWidget);
        textEdit_log->setObjectName(QStringLiteral("textEdit_log"));

        horizontalLayout_2->addWidget(textEdit_log);

        label_status = new QLabel(centralWidget);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setMaximumSize(QSize(9999, 16777215));
        label_status->setFont(font2);
        label_status->setFrameShape(QFrame::Box);
        label_status->setFrameShadow(QFrame::Sunken);
        label_status->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_status);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 90);
        gridLayout->setRowStretch(2, 1);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Client", 0));
        labelTitle->setText(QApplication::translate("MainWindow", "Nurse Station View", 0));
        QTableWidgetItem *___qtablewidgetitem = tblRooms->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Room #", 0));
        pushButton_link->setText(QApplication::translate("MainWindow", "Link URL", 0));
        lineEdit_message->setPlaceholderText(QApplication::translate("MainWindow", "Type here message", 0));
        pushButton_send->setText(QApplication::translate("MainWindow", "Send", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tblTasks->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Task", 0));
        pushButton_connect->setText(QApplication::translate("MainWindow", "Connect to server", 0));
        pushButton_disconnect->setText(QApplication::translate("MainWindow", "Disconnect from server", 0));
        label_status->setText(QApplication::translate("MainWindow", "status", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
