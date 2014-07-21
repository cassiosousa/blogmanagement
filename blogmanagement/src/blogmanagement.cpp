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

#include "blogmanagement.h"
//#include "blogmanagementview.h"
#include "settings.h"

#include <QtGui/QDropEvent>
#include <QtGui/QPainter>
#include <QtGui/QPrinter>

#include <KConfigDialog>
#include <KStatusBar>

#include <KAction>
#include <KActionCollection>
#include <KStandardAction>
#include <KIcon>

#include <KLocale>
#include <QVBoxLayout>

BlogManagement::BlogManagement()
    : KXmlGuiWindow(),
      
      m_printer(0)
{
    // accept dnd
    setAcceptDrops(true);

    // tell the KXmlGuiWindow that this is indeed the main widget
    //m_view->setupUi(this);
    setupUi(this);
   // setCentralWidget(this->centralwidget);

    // then, setup our actions
    setupActions();

    // add a status bar
    statusBar()->show();

    // a call to KXmlGuiWindow::setupGUI() populates the GUI
    // with actions, using KXMLGUI.
    // It also applies the saved mainwindow settings, if any, and ask the
    // mainwindow to automatically save settings if changed: window size,
    // toolbar position, icon size, etc.
    setupGUI();
    
    setupInitial();
    loadBlogs();
}

BlogManagement::~BlogManagement()
{
}

void BlogManagement::setupActions()
{
    //KStandardAction::openNew(this, SLOT(fileNew()), actionCollection());
   // KStandardAction::quit(qApp, SLOT(closeAllWindows()), actionCollection());

    KStandardAction::preferences(this, SLOT(optionsPreferences()), actionCollection());

    // custom menu and menu item - the slot is in the class BlogManagementView
    //KAction *custom = new KAction(KIcon("colorize"), i18n("Swi&tch Colors"), this);
    //actionCollection()->addAction( QLatin1String("switch_action"), custom );
    //connect(custom, SIGNAL(triggered(bool)), m_view, SLOT(switchColors()));
}

void BlogManagement::fileNew()
{
    // this slot is called whenever the File->New menu is selected,
    // the New shortcut is pressed (usually CTRL+N) or the New toolbar
    // button is clicked

    // create a new window
    (new BlogManagement)->show();
}

void BlogManagement::optionsPreferences()
{
    // The preference dialog is derived from prefs_base.ui
    //
    // compare the names of the widgets in the .ui file
    // to the names of the variables in the .kcfg file
    //avoid to have 2 dialogs shown
    if ( KConfigDialog::showDialog( "settings" ) )  {
        return;
    }
    KConfigDialog *dialog = new KConfigDialog(this, "settings", Settings::self());
    QWidget *generalSettingsDlg = new QWidget;
    ui_prefs_base.setupUi(generalSettingsDlg);
    dialog->addPage(generalSettingsDlg, i18n("General"), "package_setting");
    //connect(dialog, SIGNAL(settingsChanged(QString)), m_view, SLOT(settingsChanged()));
    dialog->setAttribute( Qt::WA_DeleteOnClose );
    dialog->show();
}

void BlogManagement::setupInitial()
{
  //show toolPrincipal
  toolPrincipal->show();
  
    
  itemComments = new KPageWidgetItem(createComments(),ki18n("Comments").toString());
  itemComments->setIcon(KIcon("comments"));
  itemComments->setHeader(ki18n("Comments").toString());
  
  itemUsers = new KPageWidgetItem(createComments(),ki18n("Users").toString());
  itemUsers->setIcon(KIcon("userbl"));
  itemUsers->setHeader(ki18n("User").toString());
  
  modelViewPages = new KPageWidgetModel(this);
  modelViewPages->addPage(itemComments);
  modelViewPages->addPage(itemUsers);
  
  kpageview->setModel(modelViewPages);
  
}

QWidget* BlogManagement::createComments()
{
  QWidget *commentsWidget = new QWidget();
  
  QVBoxLayout *layout = new QVBoxLayout();
  
  this->scrollAreaComments = new QScrollArea(new QLabel("Teste"));
  
  layout->addWidget(scrollAreaComments);
  
  commentsWidget->setLayout(layout);
  
  return commentsWidget;
}

void BlogManagement::loadBlogs(){
  
//  BlogUtil blogUtil("http://www.cassiosousa.com.br/blog/xmlrpc.php","cassiosousa","");
  
  //map<int,string> blogs = blogUtil.getBlogs();
  
  int chave;
  string valor;
  
  KComboBox *comboBlogs = new KComboBox( false, this);
  
  //for (map<int, string>::iterator it = blogs.begin(); it != blogs.end(); ++it) {
 //     chave = it->first;
 //     valor = it->second;
      //comboBlogs->insertItem(chave, valor);
 // }
  comboBlogs->insertItem(3,"Teste");
  this->toolPrincipal->addWidget(comboBlogs);
}

#include "blogmanagement.moc"
