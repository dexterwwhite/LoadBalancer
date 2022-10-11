#ifndef _LOADBALANCER_H_
#define _LOADBALANCER_H_

#include <vector>
#include <queue>
#include <mutex>
#include "queue.h"
#include "webserver.h"

class WebServer;

class LoadBalancer
{	
    private:
        Queue reqQueue;
        std::vector<WebServer> allServers;
        std::queue<int> readyServers;
        std::mutex mtx;

    public:
        LoadBalancer(int initialRequests, int numServers);

        void run(int runningTime);
        void serverIsDone(int serverId);
};

#endif