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

#ifndef BLOGMANAGEMENTVIEW_H
#define BLOGMANAGEMENTVIEW_H

#include <QtGui/QWidget>

#include "ui_blogmanagementview_base.h"

class QPainter;
class KUrl;

/**
 * This is the main view class for BlogManagement.  Most of the non-menu,
 * non-toolbar, and non-statusbar (e.g., non frame) GUI code should go
 * here.
 *
 * @short Main view
 * @author Cássio Alexandre de Sousa <cassio.army@gmail.com>
 * @version 0.1
 */

class BlogManagementView : public QWidget, public Ui::blogmanagementview_base
{
    Q_OBJECT
public:
    /**
     * Default constructor
     */
    BlogManagementView(QWidget *parent);

    /**
     * Destructor
     */
    virtual ~BlogManagementView();

private:
    Ui::blogmanagementview_base ui_blogmanagementview_base;

signals:
    /**
     * Use this signal to change the content of the statusbar
     */
    void signalChangeStatusbar(const QString& text);

    /**
     * Use this signal to change the content of the caption
     */
    void signalChangeCaption(const QString& text);

private slots:
    void switchColors();
    void settingsChanged();
};

#endif // BlogManagementVIEW_H
