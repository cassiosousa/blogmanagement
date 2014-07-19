#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'mainwindow_base.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_BASE_H
#define UI_MAINWINDOW_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "kpageview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionReload;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    KPageView *kpageview;
    QStatusBar *statusbar;
    QToolBar *toolPrincipal;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(937, 715);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionReload = new QAction(MainWindow);
        actionReload->setObjectName(QString::fromUtf8("actionReload"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("view-refresh");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionReload->setIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        kpageview = new KPageView(centralwidget);
        kpageview->setObjectName(QString::fromUtf8("kpageview"));
        sizePolicy.setHeightForWidth(kpageview->sizePolicy().hasHeightForWidth());
        kpageview->setSizePolicy(sizePolicy);
        kpageview->setFaceType(KPageView::List);

        verticalLayout_2->addWidget(kpageview);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolPrincipal = new QToolBar(MainWindow);
        toolPrincipal->setObjectName(QString::fromUtf8("toolPrincipal"));
        toolPrincipal->setIconSize(QSize(32, 32));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolPrincipal);

        toolPrincipal->addAction(actionReload);
        toolPrincipal->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(tr2i18n("MainWindow", 0));
        actionReload->setText(tr2i18n("Reload", 0));
#ifndef UI_QT_NO_TOOLTIP
        actionReload->setToolTip(tr2i18n("Reload", 0));
#endif // QT_NO_TOOLTIP
        toolPrincipal->setWindowTitle(tr2i18n("toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_BASE_H

