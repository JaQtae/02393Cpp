#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    ParkingArea area = ParkingArea();

    cout << "Initial parking spaces occupancy:" << endl;
    area.display();

    vector<string> v;

    cout << endl << "Parking spaces search result with an empty vector of owners:" << endl;
    area.findVehicles(v);

    v.push_back("Fie");
    v.push_back("Georg");
    cout << endl << "Parking spaces search result with non-existent owners:" << endl;
    area.findVehicles(v);

    v.push_back("Bob");
    cout << endl << "Parking spaces search result with one existing owners:" << endl;
    area.findVehicles(v);

    v.insert(v.begin(), "Claire");
    cout << endl << "Parking spaces search result with two existing owners:" << endl;
    area.findVehicles(v);

    return 0;
}
