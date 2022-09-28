#include "request.h"

using std::string;

Request::Request() : senderAddress(""), receiverAddress(""), clockCycles(0)
{
    senderAddress = "abc";
    receiverAddress = "def";
    clockCycles = 1000;
}

string Request::getSenderAddress()
{
    return senderAddress;
}

string Request::getReceiverAddress()
{
    return receiverAddress;
}

long Request::getClockCycles()
{
    return clockCycles;
}