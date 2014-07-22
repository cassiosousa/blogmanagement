/* 
 * File:   BlogUtil.cpp
 * Author: cassio
 * 
 * Created on July 12, 2014, 9:43 PM
 */

#include <stdlib.h>

#include "blogutil.h"

BlogUtil::BlogUtil(string blogUrl, string username, string password) {
    this->blogUrl = blogUrl;
    this->username = username;
    this->password = password;
}

BlogUtil::~BlogUtil() {
}

map<unsigned int, string> BlogUtil::getBlogs() {
    
    xmlrpc_c::paramList parametros;
      
    parametros.add(xmlrpc_c::value_string(this->username));
    parametros.add(xmlrpc_c::value_string(this->password));
    
    xmlrpc_c::value resultado = call(parametros, "wp.getUsersBlogs");
    
    map<unsigned int, string> result;
    
    xmlrpc_c::carray arr = xmlrpc_c::value_array(resultado).cvalue();
    xmlrpc_c::cstruct str;
    
    unsigned int idBlog;
    for(xmlrpc_c::carray::iterator it = arr.begin(); it != arr.end(); ++it){
        
        str = xmlrpc_c::value_struct( it->cValueP ).cvalue();        
        idBlog = atoi( xmlrpc_c::value_string(str.at("blogid")).crlfValue().data());
        
        result.insert(pair<int,string>( idBlog ,xmlrpc_c::value_string( str.at("blogName"))));
    }
    
    return result;
    //delete resultado;
}

//http://www.cassiosousa.com.br/blog/xmlrpc.php
xmlrpc_c::value BlogUtil::call(xmlrpc_c::paramList param, string operation){
    
    xmlrpc_c::clientSimple myClient;
     
    xmlrpc_c::value result;
    myClient.call(this->blogUrl, operation ,param, &result);
    // Assume the method returned an integer; throws error if not
    xmlrpc_c::carray arr = xmlrpc_c::value_array(result).cvalue();
    cout << arr.at(0).type();
    xmlrpc_c::cstruct str = xmlrpc_c::value_struct( arr.at(0) ).cvalue();


     string s = xmlrpc_c::value_string( str.at("blogName"));
    //string str = string( xmlrpc_c::value_string( arr[0] ) );
    cout << "Result of RPC (sum of 5 and 7): " << s << endl;
    return result;
}


