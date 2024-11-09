#include "Passenger.h"

Passenger::Passenger()
:passId(0),pickPoint(' '),dropPoint(' '),pickTime(0),dropTime(0),Amount(0)
{
}

Passenger::Passenger(int passId, char pickPoint, char dropPoint, int pickTime, int dropTime, int Amount)
{
    this->passId = passId;
    this->pickPoint = pickPoint;
    this->dropPoint = dropPoint;
    this->pickTime = pickTime;
    this->dropTime = dropTime;
    this->Amount = Amount;
}
