#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    ParkingArea area = ParkingArea();

    cout << "Initial parking spaces occupancy:" << endl;
    area.display();

    area.leave("AB123XY");
    cout << endl << "After the vehicle with license plate AB123XY has left the parking space:" << endl;
    area.display();

    area.leave("EF456SA");
    cout << endl << "After the vehicle with license plate EF456SA has left the parking space:" << endl;
    area.display();

    area.leave("EF456SA");
    cout << endl << "After trying to notify again that the vehicle with license plate EF456SA has left the parking space:" << endl;
    area.display();

    area.leave("IJ102LK");
    cout << endl << "After trying to notify that the vehicle with license plate IJ102LK - which is NOT parked - has left the parking space:" << endl;
    area.display();

    area.leave("GH102MN");
    cout << endl << "After the vehicle with license plate GH102MN has left the parking space:" << endl;
    area.display();

    return 0;
}
