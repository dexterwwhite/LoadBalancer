#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <string>
#include <queue>
#include "request.h"

/** @brief The Queue class is a modified standard library queue.

    The Queue class essentially functions the same as a C++ standard library queue, with a few modifications.
    This class is only meant to be a queue for Request objects, and uses a standard library queue of Request 
    objects for its inner queue functionality.
    @author Dexter White
    @date October 2022
    */
class Queue
{	
    private:
        std::queue<Request> reqQueue; /**< A standard library queue of Request Objects */

    public:
        /** Constructor for the Queue class.
            Initializes a Queue object and populates it with Request objects equal to the integer 
            given as a parameter.
            @param initialRequests - Number of Request objects to initially populate the Queue object with.
        */
        Queue(int initialRequests);

        /** Adds a Request object to the back of the Queue.
            @param req - The Request object that is being added to the Queue.
        */
        void push(Request req);

        /** Removes and returns the front Request of the Queue.
            @return The front Request of the Queue.
        */
        Request pop();

        /** Returns the number of Request objects in the Queue.
            @return the size of the Queue.
        */
        int size();

        /** Returns whether the Queue is empty or not.
            @return True if the Queue is empty, False if not.
        */
        bool isEmpty();
};

#endif