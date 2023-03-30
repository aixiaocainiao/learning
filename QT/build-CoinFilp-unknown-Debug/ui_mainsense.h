/********************************************************************************
** Form generated from reading UI file 'mainsense.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSENSE_H
#define UI_MAINSENSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainSense
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainSense)
    {
        if (MainSense->objectName().isEmpty())
            MainSense->setObjectName(QStringLiteral("MainSense"));
        MainSense->resize(400, 300);
        actionQuit = new QAction(MainSense);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainSense);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainSense->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainSense);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 28));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainSense->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionQuit);

        retranslateUi(MainSense);

        QMetaObject::connectSlotsByName(MainSense);
    } // setupUi

    void retranslateUi(QMainWindow *MainSense)
    {
        MainSense->setWindowTitle(QApplication::translate("MainSense", "MainSense", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainSense", "\351\200\200\345\207\272", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainSense", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainSense: public Ui_MainSense {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSENSE_H
