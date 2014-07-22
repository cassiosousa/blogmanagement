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

#ifndef BLOGMANAGEMENT_H
#define BLOGMANAGEMENT_H


#include <KXmlGuiWindow>

#include "ui_mainwindow_base.h"
#include "ui_prefs_base.h"
#include "blogutil.h"

#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/client_simple.hpp>

#include <KPageWidgetItem>
#include <KPageWidgetModel>
#include <KComboBox>
#include <QWidget>

#include <QScrollArea>
//#include "ui_mainwindow_base.h"
//class BlogManagementView;
//class MainWindow;
class QPrinter;
class KToggleAction;
class KUrl;

/**
 * This class serves as the main window for BlogManagement.  It handles the
 * menus, toolbars and status bars.
 *
 * @short Main window class
 * @author Cássio Alexandre de Sousa <cassio.army@gmail.com>
 * @version 0.1
 */
class BlogManagement : public KXmlGuiWindow,  public Ui::MainWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    BlogManagement();

    /**
     * Default Destructor
     */
    virtual ~BlogManagement();

private slots:
    void fileNew();
    void optionsPreferences();
    void settingsChanged();
    void testConnection();
    
private:
    void setupActions();
    void setupInitial();
    QWidget* createComments();
    void loadBlogs();

    signals:
  /**
     * Use this signal to change the content of the statusbar
     */
    void signalChangeStatusbar(const QString& text);
    
private:
    Ui::prefs_base 	ui_prefs_base ;

    QPrinter   		*m_printer;
    KToggleAction 	*m_toolbarAction;
    KToggleAction 	*m_statusbarAction;
    KPageWidgetModel 	*modelViewPages;
    KPageWidgetItem 	*itemComments;
    KPageWidgetItem 	*itemUsers;
    QScrollArea 	*scrollAreaComments;
    
};

#endif // _BLOGMANAGEMENT_H_
