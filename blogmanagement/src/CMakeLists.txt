set(blogmanagement_SRCS 
   utils.cpp
   blogutil.cpp
   blogmanagement.cpp
   main.cpp   
   settings.cpp
 )
#blogmanagementview.cpp
#blogmanagementview_base.ui
kde4_add_ui_files(blogmanagement_SRCS prefs_base.ui mainwindow_base.ui)

kde4_add_kcfg_files(blogmanagement_SRCS settings.kcfgc )

kde4_add_app_icon(blogmanagement_SRCS "hi*-app-krep.png" "hi*-app-comments.png" "hi*-app-userbl.png")

kde4_add_executable(blogmanagement ${blogmanagement_SRCS})

target_link_libraries(blogmanagement ${KDE4_KDEUI_LIBS} ${XMLRPC_LIBRARIES} xmlrpc_client++
#/opt/xmlrpc/stable/src/cpp/libxmlrpc++.so
#/opt/xmlrpc/stable/src/cpp/libxmlrpc_packetsocket.so
#/opt/xmlrpc/stable/lib/expat/xmlparse/libxmlrpc_xmlparse.so
#/opt/xmlrpc/stable/lib/expat/xmltok/libxmlrpc_xmltok.so
#/opt/xmlrpc/stable/lib/libutil/libxmlrpc_util.so
#/opt/xmlrpc/stable/src/libxmlrpc.so -lxmlrpc++
)

install(TARGETS blogmanagement ${INSTALL_TARGETS_DEFAULT_ARGS} )


########### install files ###############

install( PROGRAMS blogmanagement.desktop  DESTINATION ${XDG_APPS_INSTALL_DIR} )
install( FILES blogmanagement.kcfg  DESTINATION  ${KCFG_INSTALL_DIR} )
install( FILES blogmanagementui.rc  DESTINATION  ${DATA_INSTALL_DIR}/blogmanagement )
