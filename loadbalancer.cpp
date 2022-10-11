#include <iostream>
#include "loadbalancer.h"

using std::cout, std::endl;

LoadBalancer::LoadBalancer(int initialRequests, int numServers) : reqQueue(initialRequests), allServers(), readyServers(), mtx()
{
	for(int i = 0; i < numServers; i++)
	{
		WebServer server(i, this);
		allServers.push_back(server);
		readyServers.push(i);
	}
}

void LoadBalancer::run(int runtime)
{
	for(int i = 1; i <= runtime; i++)
	{
		cout << "i: " << i << endl;
	}
}

void LoadBalancer::serverIsDone(int serverId)
{
	readyServers.push(serverId);
}