#include "Taxi.h"

Taxi::Taxi()
:taxiId(0),totalEarnings(0),currentEarning(0),freeTime(0),currentPos(' '),PassengerMap()
{

}
Taxi::Taxi(int id)
{
    this->taxiId = id;
    totalEarnings = 0;
    currentEarning = 0;
    freeTime = 6;
    currentPos = 'A';
}
