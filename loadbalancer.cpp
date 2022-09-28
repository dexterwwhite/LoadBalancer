#include <iostream>
#include "request.h"

using std::cout, std::endl, std::string;

int main()
{
    Request tester;
    cout << tester.getSenderAddress() << endl;
    cout << tester.getReceiverAddress() << endl;
    cout << tester.getClockCycles() << endl;
    return 0;
}