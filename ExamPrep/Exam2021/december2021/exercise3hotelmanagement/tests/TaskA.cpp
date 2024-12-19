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

    hotel.addRoom("Waterlily");
    cout << endl << "After adding room 'Waterlily' again:" << endl;
    hotel.display();

    hotel.addRoom("Iris");
    cout << endl << "After adding room 'Iris':" << endl;
    hotel.display();

    return 0;
}
