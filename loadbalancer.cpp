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
	//Checks whether LoadBalancer will run for runtime duration or until completion of Requests
	if(toCompletion == 1)
	{
		runToCompletion = true;
	}

	//Used for tracking Request processing
	int initialsize = reqQueue.size();
	int addedCount = reqQueue.size();
	int processedCount = 0;

	//Main "run" loop
	while(clock < runtime || runToCompletion)
	{
		//Adds Request objects to Request Queue randomly
		if((rand() % 12 + 1) == 1)
		{
			Request req;
			reqQueue.push(req);
			addedCount++;
		}

		//Output Request processing completion if a request completion time exists at this clock cycle
		if(completedRequests.find(clock) != completedRequests.end())
		{
			processedCount++;
			cout << "At time " << clock << ", server " << completedRequests.at(clock).first << " processed the " << completedRequests.at(clock).second << endl;
			readyServers.push(completedRequests.at(clock).first);
			completedRequests.erase(clock);
		}

		//While there are available servers and Requests in the queue, loops until either of these are not the case
		while(readyServers.size() > 0 && !reqQueue.isEmpty())
		{
			WebServer* server = &allServers.at(readyServers.front());
			pair<int, pair<int, Request>> processedRequest = server->processRequest(reqQueue.pop(), clock);

			//To ensure there are not duplicate key values added to the map, increments the requests completion time to next available integer.
			while(completedRequests.find(processedRequest.first) != completedRequests.end())
			{
				processedRequest.first += 1;
			}
			completedRequests.insert({processedRequest.first, processedRequest.second});
			readyServers.pop();
		}

		//Increments clock cycle
		clock++;

		//If all Requests within the Queue have been processed, the loop exits
		if(addedCount == processedCount)
		{
			break;
		}
	}

	//Outputs Request processing metrics
	cout << "Initial Queue size: " << initialsize << endl;
	cout << "Final Queue size: " << reqQueue.size() << endl;
	cout << "Total Requests: " << addedCount << endl;
	cout << "Processed Requests: " << processedCount << endl;
}