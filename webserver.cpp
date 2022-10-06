#include "webserver.h"

using std::string;

WebServer::WebServer(string serverName) : name(serverName) {}

bool WebServer::processRequest(Request req)
{
    long i = 0;
    while(i < req.getClockCycles())
    {
        i++;
    }
    return true;
}