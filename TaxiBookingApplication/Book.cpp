#include <iostream>
#include <cmath>

#include "Book.h"

std::map<int, Taxi> Book::taxiMap;
int Book::noOfTaxi = 4;
int Book::id = 1;

// ***************************  Create Taxis  *******
void Book::createTaxis()
{
    for(int i = 0; i < noOfTaxi; i++)
    {
        taxiMap[i+1] = Taxi(i+1);
    }
}

// *********************** Display Taxis **************
void Book::DisplayTaxis()
{
    for(auto x : taxiMap)
    {
        Taxi t = x.second;

        std::cout << "\nTaxi id: " << t.taxiId << " " << " Total Earnings: " << t.totalEarnings << " CurrentPos: " << t.currentPos << " Free Time: " << t.freeTime;
        std::map<int, Passenger> passMap = t.PassengerMap;
        for(auto y : passMap)
        {
            Passenger p = y.second;
            std::cout << "\nBooking Id: " << p.passId << " Customer Id: " << p.passId << " From: " << p.pickPoint << " To: " << p.dropPoint << " pickUpTime: " << p.pickTime << " DropTime: " << p.dropTime << " Amount: " << p.Amount;

        }
    }
}



// ************************************ get free taxi list ************
// free taxi & time ku vara mudiyuta taxi
std::vector<Taxi> Book::getFreeTaxi(int passId, char pickPoint, char dropPoint, int pickTime)
{
    std::vector<Taxi> freeTaxi;
    for(auto it = taxiMap.begin(); it != taxiMap.end(); it++)
    {
        Taxi t = it->second;
        int disBtwPickPointAndCurrenPos = std::abs(pickPoint - t.currentPos);
        if(t.freeTime <= pickTime && (pickTime-t.freeTime >= std::abs(t.currentPos - pickPoint))){
            freeTaxi.push_back(t);
        }
    }
    return freeTaxi;

}
// F E D C B A
// ************************************ booking *********************
/*
bool Book::checker(Taxi a, Taxi b)
{
    return a.totalEarnings < b.totalEarnings;
}*/
void Book::booking(int passId, char pickPoint, char dropPoint, int pickTime)
{
    std::vector<Taxi> freeTaxiList = getFreeTaxi(passId, pickPoint, dropPoint, pickTime);

    if(freeTaxiList.size() == 0)
    {
        std::cout << "\nNo Taxi Available!!";
        return;
    }
    std::sort(freeTaxiList.begin(), freeTaxiList.end(),[](const Taxi& a, Taxi& b){
                return a.totalEarnings < b.totalEarnings;
              } ); // sorted taxi list based on total earning........

    Taxi taxi;
    int miniDis = 999;
    int distBtwPickPointAndCurrentPos = 0;
    // pakkathula irukura taxi edukanum
    for(Taxi& t : freeTaxiList)
    {
        distBtwPickPointAndCurrentPos = std::abs(pickPoint - t.currentPos);
        if(distBtwPickPointAndCurrentPos <= miniDis)
        {
            taxi = t;
            miniDis = distBtwPickPointAndCurrentPos;
        }
    }
    int taxiId = taxi.taxiId;
    taxiMap[taxiId].currentPos = pickPoint;
    taxiMap[taxiId].freeTime = pickTime + std::abs(pickPoint - dropPoint);
    int totalEarning = taxiMap[taxiId].totalEarnings;
    int dropTime = 0;
    int totalKM = 0;
    int calculation = 0;
    totalKM = std::abs(pickPoint - dropPoint) * 15;
    calculation = 100 + (totalKM - 5) * 10;
    totalEarning += calculation;
    dropTime = pickTime + std::abs(pickPoint - dropPoint);
    taxiMap[taxiId].totalEarnings = totalEarning;
    taxiMap[taxiId].PassengerMap[passId] = Passenger(passId, pickPoint, dropPoint, pickTime, dropTime, calculation);
    std::cout << "\nBooked Successfully!!";
}
/*
Taxi No:    Total Earnings:
BookingID    CustomerID    From    To    PickupTime    DropTime    Amount

Output:
Taxi-1    Total Earnings: Rs. 400

1     1     A    B    9    10    200
3     3     B    C    12   13    200
*/
// ********************************************** initiate booking *******************
void Book::initiateBooking()
{
    int passId = Book::id;
    char pickPoint = ' ';
    char dropPoint = ' ';
    int pickTime = 0;

    std::cout << "\nPassenger Id: " << passId;
    std::cout << "\nPick Point: ";
    std::cin >> pickPoint;
    if(pickPoint < 'A' || pickPoint > 'F'){
        std::cout << "\nInvalid Pick Point!!";
        return;
    }
    std::cout << "Drop Point: ";
    std::cin >> dropPoint;
    if(dropPoint < 'A' || dropPoint > 'F'){
        std::cout << "\nInvalid Drop Point!!";
        return;
    }
    std::cout << "Pick Time: ";
    std::cin >> pickTime;

    booking(passId, pickPoint, dropPoint, pickTime);
    Book::id++;
}








