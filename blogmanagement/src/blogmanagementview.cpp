/***************************************************************************
 *   Copyright (C) 2014 by Cássio Alexandre de Sousa <cassio.army@gmail.com>                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include "blogmanagementview.h"
#include "settings.h"

#include <KLocale>
#include <QtGui/QLabel>

BlogManagementView::BlogManagementView(QWidget *parent)
{
    ui_blogmanagementview_base.setupUi(parent);
    settingsChanged();
    setAutoFillBackground(true);
}

BlogManagementView::~BlogManagementView()
{

}

void BlogManagementView::switchColors()
{
    // switch the foreground/background colors of the label
    QColor color = Settings::col_background();
    Settings::setCol_background( Settings::col_foreground() );
    Settings::setCol_foreground( color );

    settingsChanged();
}

void BlogManagementView::settingsChanged()
{
    QPalette pal;
    pal.setColor( QPalette::Window, Settings::col_background());
    pal.setColor( QPalette::WindowText, Settings::col_foreground());
    ui_blogmanagementview_base.kcfg_sillyLabel->setPalette( pal );

    // i18n : internationalization
    ui_blogmanagementview_base.kcfg_sillyLabel->setText( i18n("This project is %1 days old",Settings::val_time()) );
    emit signalChangeStatusbar( i18n("Settings changed") );
}

#include "blogmanagementview.moc"
