#ifndef _REQUEST_H_
#define _REQUEST_H_

#include <iostream>
#include <string>
#include <stdlib.h>
using std::string, std::ostream;

class Request
{	
    private:
        string senderAddress;
        string receiverAddress;
        long clockCycles;

    public:
        Request();
        
        string getSenderAddress();
        string getReceiverAddress();
        long getClockCycles();

        friend ostream& operator<<(ostream& os, const Request& req);
};

#endif