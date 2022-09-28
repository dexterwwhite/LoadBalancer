#ifndef _REQUEST_H_
#define _REQUEST_H_

#include <string>
using std::string;

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
};

#endif
