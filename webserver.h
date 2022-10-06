#ifndef _WEBSERVER_H_
#define _WEBSERVER_H_

#include <string>
#include "request.h"

using std::string;

class WebServer
{	
    private:
        string name;

    public:
        WebServer(string serverName);

        bool processRequest(Request req);
};

#endif