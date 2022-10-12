#include <iostream>
#include <unistd.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "request.h"
#include "queue.h"
#include "loadbalancer.h"
#include "webserver.h"

using std::cout, std::endl, std::string;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int opt;
    int runningTime = 10000;
    int numServers = 10;
    int initialRequests = 500;
	int toCompletion = 0;

    while ((opt = getopt(argc, argv, "t:w:r:c:")) != -1) 
    {
		switch (opt) {
			case 't':
				runningTime = atoi(optarg);
				break;
			case 'w':
				numServers = atoi (optarg);
				break;
			case 'r':
				initialRequests = atoi(optarg);
				break;
			case 'c':
				toCompletion = atoi(optarg);
				break;
		}
    }

	LoadBalancer loadBalancer(initialRequests, numServers);
	loadBalancer.run(toCompletion, runningTime);

    return 0;
}