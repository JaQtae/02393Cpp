#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    ParkingArea area = ParkingArea();

    cout << "Initial parking spaces occupancy:" << endl;
    area.display();

    area.park("LYNGBY04", "IJ102LK", "Eric", MOTORBIKE);
    cout << endl << "After trying to park Eric's motorbike inside parking space LYNGBY04:" << endl;
    area.display();

    area.park("LYNGBY01", "KL394PO", "Fie", CAR);
    cout << endl << "After trying to park Fie's car inside parking space LYNGBY01:" << endl;
    area.display();

    area.leave("EF456SA");
    cout << endl << "After the vehicle with license plate EF456SA has left the parking space:" << endl;
    area.display();

    cout << endl << "Parking area contains the following misplaced vehicles:" << endl;
    area.findMisplacedVehicles();

    cout << endl << "Parking space(s) containing vehicles with license plate AB123XY or CD987WQ:" << endl;
    vector<string> v;
    v.push_back("AB123XY");
    v.push_back("CD987WQ");
    area.findVehicles(v);

    return 0;
}
