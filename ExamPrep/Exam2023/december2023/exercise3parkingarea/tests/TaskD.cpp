#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    ParkingArea area = ParkingArea();

    cout << "Initial parking spaces occupancy:" << endl;
    area.display();

    vector<string> v;

    cout << endl << "Parking spaces search result with an empty vector of license plates:" << endl;
    area.findVehicles(v);

    v.push_back("IJ102LK");
    v.push_back("KL394PO");
    cout << endl << "Parking spaces search result with non-existent license plates:" << endl;
    area.findVehicles(v);

    v.push_back("CD987WQ");
    cout << endl << "Parking spaces search result with one existing license plates:" << endl;
    area.findVehicles(v);

    v.insert(v.begin(), "GH102MN");
    cout << endl << "Parking spaces search result with two existing license plates:" << endl;
    area.findVehicles(v);

    return 0;
}
