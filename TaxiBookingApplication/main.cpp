#include <iostream>
#include <string>

#include "Book.h"
using namespace std;
void module()
{
    cout << "\n1.Book Taxi";
    cout << "\n2.Display Taxies";
    cout << "\n3.Exit\n";

}

int main()
{
    cout << "\t\tGreen Taxi Application!!" << endl;
    Book b;
    b.createTaxis();
    bool flag = true;
    int choice = 0;
    while(flag){
        module();
        cin >> choice;
        switch(choice)
        {
        case 1:
            {
                // book taxi
                Book b;
                b.initiateBooking();
                break;
            }
        case 2:
            {
                // display taxis
                Book b;
                b.DisplayTaxis();
                break;
            }
        case 3:
            {
                // exit
                flag = false;
                break;
            }
        default:
            {
                cout << "\nInvalid Try!!";
                break;
            }
        }
    }

}
