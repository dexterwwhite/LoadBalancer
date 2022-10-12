#ifndef _LOADBALANCER_H_
#define _LOADBALANCER_H_

#include <vector>
#include <queue>
#include <unordered_map>
#include "queue.h"
#include "webserver.h"

class WebServer;

class LoadBalancer
{	
    private:
        Queue reqQueue;
        std::vector<WebServer> allServers;
        std::queue<int> readyServers;
        std::unordered_map<int, pair<int, Request>> completedRequests;
        int clock;
        bool runToCompletion;

    public:
        LoadBalancer(int initialRequests, int numServers);

        void run(int toCompletion, int runningTime);
};

#endif