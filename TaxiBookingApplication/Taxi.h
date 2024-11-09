#ifndef TAXI_H_INCLUDED
#define TAXI_H_INCLUDED
#include <map>
#include "Passenger.h"
class Taxi
{
public:
    int taxiId;
    int totalEarnings;
    int currentEarning;
    int freeTime;
    char currentPos;
    std::map<int, Passenger> PassengerMap;

    Taxi();
    Taxi(int id);
};

#endif // TAXI_H_INCLUDED
