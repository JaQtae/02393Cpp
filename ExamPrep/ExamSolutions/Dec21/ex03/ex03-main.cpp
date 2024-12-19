#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    Hotel hotel = Hotel();

    cout << "Initial hotel occupancy:" << endl;
    hotel.display();

    hotel.addRoom("Waterlily");
    cout << endl << "After adding room 'Waterlily':" << endl;
    hotel.display();

    hotel.addGuest("Waterlily", "Taika Waititi", "pqr567");
    cout << endl << "After adding a guest:" << endl;
    hotel.display();

    cout << endl << "Room(s) occupied by someone called Alan Smithee:" << endl;
    hotel.findRoomByGuest("Alan Smithee", "*");

    return 0;
}
