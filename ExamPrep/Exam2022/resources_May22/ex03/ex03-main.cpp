#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    Hotel hotel = Hotel();

    cout << "Initial hotel occupancy:" << endl;
    hotel.display();

    hotel.renameRoom("Lotus", "Waterlily");
    cout << endl << "After renaming room 'Lotus' to 'Waterlily':" << endl;
    hotel.display();

    hotel.removeGuest("Orchid", "Alan Smithee", "abc123");
    cout << endl << "After removing a guest:" << endl;
    hotel.display();

    cout << endl << "Room(s) with guests with id '123xyz' or '456abc':" << endl;
    vector<string> v;
    v.push_back("123xyz");
    v.push_back("456abc");
    hotel.findRoomByGuestId(v);

    return 0;
}
