/* 
 * File:   BlogUtil.h
 * Author: cassio
 *
 * Created on July 12, 2014, 9:43 PM
 */

#ifndef BLOGUTIL_H
#define	BLOGUTIL_H

#include <iostream>
#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/client_simple.hpp>

using namespace std;
class BlogUtil {
public:
       
    BlogUtil(string blogUrl,string,string);
    virtual ~BlogUtil();
    
    map<int,string> getBlogs();
private:
    string blogUrl;
    string username;
    string password;
    
    xmlrpc_c::value call(xmlrpc_c::paramList param, string operation);
};

#endif	/* BLOGUTIL_H */

