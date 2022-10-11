#ifndef _WEBSERVER_H_
#define _WEBSERVER_H_

#include <string>
#include "request.h"
#include "loadbalancer.h"

using std::string;

class LoadBalancer;

class WebServer
{	
    private:
        int serverId;
        LoadBalancer* loadBalancer;

    public:
        WebServer(int id, LoadBalancer* balancer);

        void processRequest(Request req);
};

#endif