#include "request.h"

using std::string, std::to_string;

Request::Request() : senderAddress(""), receiverAddress(""), clockCycles(0)
{
    senderAddress = to_string(rand() % 255) + "." + to_string(rand() % 255) + "." + to_string(rand() % 255) + "." + to_string(rand() % 255);
    receiverAddress = to_string(rand() % 255) + "." + to_string(rand() % 255) + "." + to_string(rand() % 255) + "." + to_string(rand() % 255);
    clockCycles = rand() % 500 + 1;
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