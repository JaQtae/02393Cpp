#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    Hotel hotel = Hotel();

    cout << "Adding a new room 'Cyclamen'" << endl;
    hotel.addRoom("Cyclamen");

    cout << "Adding a new room 'Gladiolus'" << endl;
    hotel.addRoom("Gladiolus");

    cout << endl << "Hotel occupancy:" << endl;
    hotel.display();

    cout << endl << "Room(s) occupied by a guest:" << endl;
    hotel.findRoomByGuest("*", "*");

    cout << endl << "Adding a guest to room 'Cyclamen'" << endl;
    hotel.addGuest("Cyclamen", "Alan Smithee", "abcdef");

    cout << endl << "Updated hotel occupancy:" << endl;
    hotel.display();

    cout << endl << "Room(s) occupied by someone called Alan Smithee:" << endl;
    hotel.findRoomByGuest("Alan Smithee", "*");

    return 0;
}
