#ifndef _LOADBALANCER_H_
#define _LOADBALANCER_H_

#include <vector>
#include <queue>
#include <unordered_map>
#include "queue.h"
#include "webserver.h"

class WebServer;

/** @brief The LoadBalancer class handles distribution of requests in order to balance server request load.

    The LoadBalancer class handles distribution of requests in order to balance server request load. This object 
    balances server load by distributing incoming requests to available WebServer objects.
    @author Dexter White
    @date October 2022
    */
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
        /** Constructor for the LoadBalancer class.
            Initializes a LoadBalancer object, initially populates its Request Queue with the 
            given number of initial requests, and initially populates its vector of all WebServer 
            objects with the given number of servers. Additionally, adds each of these webservers to 
            the queue of available servers.
            @param initialRequests - The initial number of Request objects to add to the Request Queue.
            @param numServers - The number of WebServer objects the LoadBalancer will work with.
        */
        LoadBalancer(int initialRequests, int numServers);

        /** Runs the LoadBalancer either to completion (processing every Request in the Queue) or a number 
            of clock cycles equal to the given runtime. While running, the LoadBalancer balances server load 
            by distributing requests to available servers. To simulate real-world processes, each clock cycle 
            there is a random chance for an additional Request to be added to the Queue.
            @param toCompletion - If toCompletion is equal to 1, the LoadBalancer will run to completion rather 
                                  than runtime clock cycles. Otherwise, will run equal to given runtime.
            @param runningTime - The number of clock cycles the LoadBalancer will run for.
        */
        void run(int toCompletion, int runningTime);
};

#endif