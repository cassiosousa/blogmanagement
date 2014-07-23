project(blogmanagement)

find_package(KDE4 REQUIRED)

#set(XMLRPC_curl_LIBRARY "/usr/lib/i386-linux-gnu/libcurl.so.4")

find_package(XMLRPC REQUIRED c++2)

message("ENABLE EXCEPTIONS")

add_definitions("-fexceptions")

include (KDE4Defaults)
#include (FindXMLRPC)

include_directories( ${KDE4_INCLUDES} ${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

#add_subdirectory( doc )
add_subdirectory( src )
add_subdirectory( icons )
