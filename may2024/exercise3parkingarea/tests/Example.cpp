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

    area.park("LYNGBY06", "MN231AX", "Georg", MOTORBIKE);
    cout << endl << "After trying to park Georg's motorbike inside parking space LYNGBY06:" << endl;
    area.display();

    vector<string> v;
    v.push_back("EF456SA");
    v.push_back("CD987WQ");
    area.leave(v);
    cout << endl << "After the vehicles with license plate EF456SA and CD987WQ have left the parking space:" << endl;
    area.display();

    cout << endl << "There are " << area.getEmptySpaces(CAR) << " available parking spaces for cars.";
    cout << endl << "There are " << area.getEmptySpaces(MOTORBIKE) << " available parking spaces for motorbikes.";
    cout << endl << "There are " << area.getEmptySpaces(TRUCK) << " available parking spaces for trucks.";

    cout << endl;
    
    cout << endl << "Parking space(s) containing vehicles belonging to Alice or Daisy:" << endl;
    vector<string> v2;
    v2.push_back("Alice");
    v2.push_back("Daisy");
    area.findVehicles(v2);

    return 0;
}
