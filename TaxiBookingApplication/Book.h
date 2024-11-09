#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Taxi.h"
#include "Passenger.h"
class Book
{
public:
    static std::map<int, Taxi> taxiMap;
    static int noOfTaxi;
    static int id;

    void createTaxis();

    void initiateBooking(); // initiate booking
    void booking(int passId, char pickPoint, char dropPoint, int pickTime);
    std::vector<Taxi> getFreeTaxi(int passId, char pickPoint, char dropPoint, int pickTime);
    //bool checker(Taxi t1, Taxi t2);
    void DisplayTaxis(); // display taxis............
};

#endif // BOOK_H_INCLUDED
