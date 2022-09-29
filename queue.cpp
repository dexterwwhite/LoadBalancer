#include "queue.h"

Queue::Queue(int initialRequests) : reqQueue()
{
    for(int i = 0; i < initialRequests; i++)
    {
        Request req;
        reqQueue.push(req);
    }
}

void Queue::push(Request req)
{
    reqQueue.push(req);
}

Request Queue::pop()
{
    Request front = reqQueue.front();
    reqQueue.pop();
    return front;
}

int Queue::size()
{
    return reqQueue.size();
}

bool Queue::isEmpty()
{
    return reqQueue.empty();
}