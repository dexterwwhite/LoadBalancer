#include "webserver.h"

using std::string;

WebServer::WebServer(int id) : serverId(id) {}

pair<int, pair<int, Request>> WebServer::processRequest(Request req, int currTime)
{
    pair<int, Request> processedRequest;
    processedRequest.first = serverId;
    processedRequest.second = req;
    pair<int, pair<int, Request>> wrappedValue;
    wrappedValue.first = currTime + req.getClockCycles();
    wrappedValue.second = processedRequest;
    return wrappedValue;
}