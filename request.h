#ifndef _REQUEST_H_
#define _REQUEST_H_

#include <iostream>
#include <string>
#include <stdlib.h>
using std::string, std::ostream;

/** @brief The Request class, which is used to mimic the functioning of a real life request.

    The Request class mimics a real life server request and does so with 3 data variables: 
    a sender IP address, a receiver IP address, and the number of clock cycles. The IP addresses 
    mimic a request being sent from one IP address to another, and the number of clock cycles 
    represent the time it would take for a server to process this request.
    @author Dexter White
    @date October 2022
    */
class Request
{	
    private:
        string senderAddress;
        string receiverAddress;
        long clockCycles;

    public:
        /** Constructor for the Request class.
            Initializes a Request object with random values for each data variable.
            Data variable senderAddress is set to a random valid IP address.
            Data variable receiverAddress is set to a random valid IP address.
            Data variable clockCycles is set to a random integer value from 1-175.
        */
        Request();
        
        /** Returns the request's sender IP address.
            @return The sender IP address of the Request.
        */
        string getSenderAddress();

        /** Returns the request's receiver IP address.
            @return The receiver IP address of the Request.
        */
        string getReceiverAddress();

        /** Returns the request's processing time in clock cycles.
            @return The processing time in clock cycles of the Request.
        */
        long getClockCycles();

        /** Formats the Request when it is output using the ostream "<<" operator.
            @param os - The ostream object used to output the Request.
            @param req - The Request object that is being output.
            @return The newly updated ostream object containing the formatted Request output.
        */
        friend ostream& operator<<(ostream& os, const Request& req);
};

#endif