#ifndef _WEBSERVER_H_
#define _WEBSERVER_H_

#include <string>
#include "request.h"

using std::string, std::pair;

class WebServer
{	
    private:
        int serverId;

    public:
        WebServer(int id);

        pair<int, pair<int, Request>> processRequest(Request req, int currTime);
};

#endif