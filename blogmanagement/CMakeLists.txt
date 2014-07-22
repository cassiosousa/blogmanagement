project(blogmanagement)

find_package(KDE4 REQUIRED)

#set(XMLRPC_curl_LIBRARY "/usr/lib/i386-linux-gnu/libcurl.so.4")

find_package(XMLRPC REQUIRED c++2)

include (KDE4Defaults)
#include (FindXMLRPC)

include_directories( ${KDE4_INCLUDES} ${QT_INCLUDES} )

#add_subdirectory( doc )
add_subdirectory( src )
add_subdirectory( icons )
