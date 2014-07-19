set(blogmanagement_SRCS 
   blogmanagement.cpp
   main.cpp   
 )
#blogmanagementview.cpp
#blogmanagementview_base.ui
kde4_add_ui_files(blogmanagement_SRCS prefs_base.ui mainwindow_base.ui)

kde4_add_kcfg_files(blogmanagement_SRCS settings.kcfgc )

kde4_add_app_icon(blogmanagement_SRCS "hi*-app-krep.png" "hi*-app-comments.png" "hi*-app-userbl.png")

kde4_add_executable(blogmanagement ${blogmanagement_SRCS})

target_link_libraries(blogmanagement ${KDE4_KDEUI_LIBS} )

install(TARGETS blogmanagement ${INSTALL_TARGETS_DEFAULT_ARGS} )


########### install files ###############

install( PROGRAMS blogmanagement.desktop  DESTINATION ${XDG_APPS_INSTALL_DIR} )
install( FILES blogmanagement.kcfg  DESTINATION  ${KCFG_INSTALL_DIR} )
install( FILES blogmanagementui.rc  DESTINATION  ${DATA_INSTALL_DIR}/blogmanagement )
