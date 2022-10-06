#include "webserver.h"

using std::string;

WebServer::WebServer(int id, LoadBalancer* balancer) : serverId(id), loadBalancer(balancer) {}

void WebServer::processRequest(Request req)
{
    long i = 0;
    while(i < req.getClockCycles())
    {
        i++;
    }
    loadBalancer->serverIsDone(serverId);
}