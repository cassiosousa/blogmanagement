#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'blogmanagementview_base.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOGMANAGEMENTVIEW_BASE_H
#define UI_BLOGMANAGEMENTVIEW_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_blogmanagementview_base
{
public:
    QGridLayout *gridLayout;
    QLabel *kcfg_sillyLabel;

    void setupUi(QWidget *blogmanagementview_base)
    {
        if (blogmanagementview_base->objectName().isEmpty())
            blogmanagementview_base->setObjectName(QString::fromUtf8("blogmanagementview_base"));
        blogmanagementview_base->resize(315, 233);
        blogmanagementview_base->setAutoFillBackground(true);
        gridLayout = new QGridLayout(blogmanagementview_base);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        kcfg_sillyLabel = new QLabel(blogmanagementview_base);
        kcfg_sillyLabel->setObjectName(QString::fromUtf8("kcfg_sillyLabel"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(119, 119, 119, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        kcfg_sillyLabel->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(12);
        kcfg_sillyLabel->setFont(font);
        kcfg_sillyLabel->setAutoFillBackground(true);
        kcfg_sillyLabel->setScaledContents(true);
        kcfg_sillyLabel->setAlignment(Qt::AlignCenter);
        kcfg_sillyLabel->setWordWrap(false);

        gridLayout->addWidget(kcfg_sillyLabel, 0, 0, 1, 1);


        retranslateUi(blogmanagementview_base);

        QMetaObject::connectSlotsByName(blogmanagementview_base);
    } // setupUi

    void retranslateUi(QWidget *blogmanagementview_base)
    {
        blogmanagementview_base->setWindowTitle(tr2i18n("kapp4_base", 0));
        kcfg_sillyLabel->setText(tr2i18n("hello, world", 0));
    } // retranslateUi

};

namespace Ui {
    class blogmanagementview_base: public Ui_blogmanagementview_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BLOGMANAGEMENTVIEW_BASE_H

