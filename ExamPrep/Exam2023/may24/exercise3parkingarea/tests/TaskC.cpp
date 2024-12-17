#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    ParkingArea area = ParkingArea();

    cout << "Initial parking spaces occupancy:" << endl;
    area.display();

    cout << endl << "There are " << area.getEmptySpaces(CAR) << " available parking spaces for cars.";
    cout << endl << "There are " << area.getEmptySpaces(MOTORBIKE) << " available parking spaces for motorbikes.";
    cout << endl << "There are " << area.getEmptySpaces(TRUCK) << " available parking spaces for trucks." << endl;

    return 0;
}
