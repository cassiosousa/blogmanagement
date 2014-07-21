/* 
 * File:   Utils.cpp
 * Author: cassio
 * 
 * Created on July 11, 2014, 10:57 PM
 */

#include "utils.h"
#include <iostream>
using namespace std;

Utils::Utils() {
}

Utils::~Utils() {
}

string Utils::getExecutablePath() {
    char result[ PATH_MAX ];
    ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
    return string( result, (count > 0) ? count : 0 );    
}

string Utils::getExecutableDirectory() {
    char result[ PATH_MAX ];
    ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
    string::size_type pos = string( result ).find_last_of( "\\/" );
    return string( result ).substr( 0, pos);    
}


