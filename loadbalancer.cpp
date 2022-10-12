#include <iostream>
#include "loadbalancer.h"

using std::cout, std::endl, std::vector;

LoadBalancer::LoadBalancer(int initialRequests, int numServers) : reqQueue(initialRequests), allServers(), readyServers(), completedRequests(), clock(0), runToCompletion(false)
{
	for(int i = 0; i < numServers; i++)
	{
		WebServer server(i);
		allServers.push_back(server);
		readyServers.push(i);
	}
}

void LoadBalancer::run(int toCompletion, int runtime)
{
	if(toCompletion == 1)
	{
		runToCompletion = true;
	}

	int addedCount = reqQueue.size();
	int processedCount = 0;

	while(clock < runtime || runToCompletion)
	{
		if(clock < runtime && (clock % (rand() % 100 + 1) == 0))
		{
			Request req;
			reqQueue.push(req);
			addedCount++;
		}

		if(completedRequests.find(clock) != completedRequests.end())
		{
			processedCount++;
			cout << "At time " << clock << ", server " << completedRequests.at(clock).first << " processed the " << completedRequests.at(clock).second << endl;
			readyServers.push(completedRequests.at(clock).first);
			completedRequests.erase(clock);
		}
		if(readyServers.size() > 0 && !reqQueue.isEmpty())
		{
			WebServer* server = &allServers.at(readyServers.front());
			pair<int, pair<int, Request>> processedRequest = server->processRequest(reqQueue.pop(), clock);
			while(completedRequests.find(processedRequest.first) != completedRequests.end())
			{
				processedRequest.first += 1;
			}
			completedRequests.insert({processedRequest.first, processedRequest.second});
			readyServers.pop();
		}
		clock++;

		if(clock > runtime && addedCount == processedCount)
		{
			break;
		}
	}
	cout << "Total Requests: " << addedCount << endl;
	cout << "Processed Requests: " << processedCount << endl;
}