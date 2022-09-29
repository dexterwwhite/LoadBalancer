#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "request.h"
#include "queue.h"

using std::cout, std::endl, std::string;

int main()
{
    srand(time(NULL));
    Queue testQueue(5);
    
    cout << "Queue is empty: " << testQueue.isEmpty() << endl;
    cout << "Queue size: " << testQueue.size() << endl;

    for(int i = 0; i < 5; i++)
    {
        cout << "Queue pop: " << testQueue.pop() << endl;
    }

    cout << "Queue is empty: " << testQueue.isEmpty() << endl;
    cout << "Queue size: " << testQueue.size() << endl;

    Request req1;
    Request req2;
    testQueue.push(req1);
    testQueue.push(req2);
    cout << "Queue is empty: " << testQueue.isEmpty() << endl;
    cout << "Queue size: " << testQueue.size() << endl;

    cout << "Request 1: " << req1 << endl;
    cout << "Request 2: " << req2 << endl;
    cout << "Queue pop 1: " << testQueue.pop() << endl;
    cout << "Queue pop 2: " << testQueue.pop() << endl;
    cout << "Queue is empty: " << testQueue.isEmpty() << endl;
    cout << "Queue size: " << testQueue.size() << endl;
    return 0;
}