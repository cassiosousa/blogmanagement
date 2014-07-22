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
    dialog->setModal(true);
    QWidget *conInfoSettingsDlg = new QWidget;
    ui_prefs_base.setupUi(conInfoSettingsDlg);
    dialog->addPage(conInfoSettingsDlg, i18n("Connection Information"), "package_setting");
    //connect(dialog, SIGNAL(settingsChanged(QString)), m_view, SLOT(settingsChanged()));
    connect(dialog, SIGNAL( settingsChanged(QString)),this, SLOT(settingsChanged()) );
    
    ui_prefs_base.kleUser->setText("TESTE");
    
    //action for test connection with blog
    connect(ui_prefs_base.kpbTestConnection, SIGNAL(clicked(bool)), this, SLOT(testConnection()) );
    
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

/**
 * load blogs from connection and show combo, on toolbar
 */
void BlogManagement::loadBlogs(){
  
  BlogUtil blogUtil("http://www.cassiosousa.com.br/blog/xmlrpc.php","cassiosousa","");
  
  map<unsigned int,string> blogs = blogUtil.getBlogs();
  
  QString newValue;
  
  KComboBox *comboBlogs = new KComboBox( false, this);
  
  for (map<unsigned int, string>::iterator it = blogs.begin(); it != blogs.end(); ++it) {
     
      newValue = QString::fromUtf8( it->second.c_str(), it->second.length() );
      
      //verify exists apostrophe in html and replace for '
      if(newValue.contains("&#039;"))
	newValue = newValue.replace("&#039;","'");
            
      comboBlogs->insertItem(it->first, newValue);
  }
  
  this->toolPrincipal->addWidget(comboBlogs);
}

void BlogManagement::settingsChanged(){
  cout << "CHAMOU" << endl;
  emit signalChangeStatusbar( i18n("Settings changed") );
}

/**
 * Method for test connection with blog
 */
void BlogManagement::testConnection(){
  cout << "CHAMOU" << endl;
  
  QString blogURL = ui_prefs_base.kleBlogUrl->userText();
  QString user = ui_prefs_base.kleUser->userText();
  QString password = ui_prefs_base.klePassword->userText();
  
  BlogUtil blogUtil(blogURL.toStdString(),user.toStdString(),password.toStdString());
  
  try{
    
    blogUtil.getBlogs();
  
    ui_prefs_base.kled->setColor(QColor(0,255,0));
  
  }catch(exception& e){
    
    KMessageBox::error(
      this,
      QString::fromUtf8( e.what(), strlen(e.what()) ),
      ki18n("Connection Failure").toString()//,
      //KMessageBox::Option::Dangerous
    );
    ui_prefs_base.kled->setColor(QColor(255,0,0));
  }
  
  emit signalChangeStatusbar( i18n("Settings changed") );
}
  
#include "blogmanagement.moc"
