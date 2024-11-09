#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED

class Passenger
{
public:
    int passId;
    char pickPoint;
    char dropPoint;
    int pickTime;
    int dropTime;
    int Amount;

    Passenger();
    Passenger(int passId, char pickPoint, char dropPoint, int pickTime, int dropTime, int Amount);
};

#endif // PASSENGER_H_INCLUDED
