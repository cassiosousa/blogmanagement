/* 
 * File:   Utils.h
 * Author: cassio
 *
 * Created on July 11, 2014, 10:57 PM
 */

#ifndef UTILS_H
#define	UTILS_H

#include <iostream>
#include <limits.h>
#include <unistd.h>

using namespace std;

class Utils {
public:
    Utils();
    virtual ~Utils();
    
    static string getExecutablePath();
    static string getExecutableDirectory();
    
private:

};

#endif	/* UTILS_H */

