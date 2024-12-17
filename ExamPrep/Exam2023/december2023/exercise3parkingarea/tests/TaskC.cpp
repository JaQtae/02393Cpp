#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    ParkingArea area = ParkingArea();

    cout << "Initial parking spaces occupancy:" << endl;
    area.display();

    vector<string> v;

    cout << endl << "Parking area contains the following misplaced vehicles:" << endl;
    area.findMisplacedVehicles();

    return 0;
}
