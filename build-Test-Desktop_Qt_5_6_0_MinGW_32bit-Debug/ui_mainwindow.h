/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *p;
    QPushButton *p_2;
    QLabel *BK;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 720);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        p = new QPushButton(centralWidget);
        p->setObjectName(QStringLiteral("p"));
        p->setGeometry(QRect(440, 520, 400, 80));
        QFont font;
        font.setPointSize(30);
        font.setBold(false);
        font.setWeight(50);
        p->setFont(font);
        p_2 = new QPushButton(centralWidget);
        p_2->setObjectName(QStringLiteral("p_2"));
        p_2->setGeometry(QRect(440, 620, 400, 80));
        QFont font1;
        font1.setPointSize(30);
        p_2->setFont(font1);
        BK = new QLabel(centralWidget);
        BK->setObjectName(QStringLiteral("BK"));
        BK->setGeometry(QRect(0, 0, 1280, 720));
        BK->setLineWidth(1);
        MainWindow->setCentralWidget(centralWidget);
        BK->raise();
        p->raise();
        p_2->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        p->setText(QApplication::translate("MainWindow", "Start", 0));
        p_2->setText(QApplication::translate("MainWindow", "Exit", 0));
        BK->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
