#ifndef _WEBSERVER_H_
#define _WEBSERVER_H_

#include <string>
#include "request.h"

using std::string;

class WebServer
{	
    private:
        int serverId;
        LoadBalancer* loadBalancer;

    public:
        WebServer(int id, LoadBalancer* balancer);

        bool processRequest(Request req);
};

#endif