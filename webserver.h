#ifndef _WEBSERVER_H_
#define _WEBSERVER_H_

#include "request.h"

using std::pair;

/** @brief The WebServer class represents a real-life web server.

    The WebServer class represents a real-life web server. This object accepts requests from 
    the LoadBalancer and "processes" the Request objects.
    @author Dexter White
    @date October 2022
    */
class WebServer
{	
    private:
        int serverId; /**< The integer identification number for this web server. */

    public:
        /** Constructor for the WebServer class.
            Initializes a WebServer object and sets its server ID number to the given parameter
            value.
            @param id - The integer identification number for the server.
        */
        WebServer(int id);

        /** "Processes" a Request object and returns information about the processing completion.
            @return A pair containing the completion time of the request processing as its first value 
                    and another pair as its second value. The nested pair contains the server ID as its 
                    first value and the initial Request as its second value.
        */
        pair<int, pair<int, Request>> processRequest(Request req, int currTime);
};

#endif