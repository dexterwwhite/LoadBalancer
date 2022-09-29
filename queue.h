#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <string>
#include <queue>
#include "request.h"

class Queue
{	
    private:
        std::queue<Request> reqQueue;

    public:
        Queue(int initialRequests);

        void push(Request req);
        Request pop();
        int size();
        bool isEmpty();
};

#endif