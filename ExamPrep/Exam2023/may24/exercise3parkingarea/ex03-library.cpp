#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
string ParkingArea::categoryToString(Category c)
{
    switch (c)
    {
    case CAR:
        return "car";
    case MOTORBIKE:
        return "motorbike";
    case TRUCK:
        return "truck";
    default:
        return "";
    }
}

// Do not modify
ParkingArea::ParkingArea() {
    this->parkingSpaces["LYNGBY01"] = CAR;
    this->parkingOccupancy["LYNGBY01"] = {"AB123XY", "Alice"};

    this->parkingSpaces["LYNGBY02"] = CAR;
    this->parkingOccupancy["LYNGBY02"] = {"CD987WQ", "Bob"};

    this->parkingSpaces["LYNGBY03"] = MOTORBIKE;
    this->parkingOccupancy["LYNGBY03"] = {"EF456SA", "Claire"};

    this->parkingSpaces["LYNGBY04"] = CAR;

    this->parkingSpaces["LYNGBY05"] = TRUCK;
    this->parkingOccupancy["LYNGBY05"] = {"GH102MN", "Daisy"};

    this->parkingSpaces["LYNGBY06"] = MOTORBIKE;
}

// Task 3(a).  Implement this method
void ParkingArea::park(string parkingSpaceID, string plate, string owner, Category category) {
    // 'this' refers to current instance of class
    // (a) pSID not in parkingSpaces
    if (this->parkingSpaces.find(parkingSpaceID) == this->parkingSpaces.end()) {
        return; // if pSID does not exist
    }
    // (b1) if pSID belongs to another category vehicle
    if (parkingSpaces[parkingSpaceID] != category) {
        return; // do nothing
    }
    // (b21) if pSID is already occupied
    if (this->parkingOccupancy.find(parkingSpaceID) != this->parkingOccupancy.end()) {
        return; // if pSID is already occupied
    }
    // (b22) pSID is empty and we're able to park. Send info about plate and owner to Vehicle
    // struct and store this Vehicle in the database
    Vehicle v = {plate, owner};
    this->parkingOccupancy[parkingSpaceID] = v;
}

// Task 3(b).  Implement this method
void ParkingArea::leave(vector<string> plates) {
}


// Task 3(c).  Implement this method
unsigned int ParkingArea::getEmptySpaces(Category category) {
	return 0;
}

// Task 3(d).  Implement this method
void ParkingArea::findVehicles(vector<string> owners) {
}

// Do not modify
void ParkingArea::display() {
    for (auto it = this->parkingSpaces.begin(); it != this->parkingSpaces.end(); it++) {
        cout << "Parking '" << it->first << "' ";
        cout << "is for a " << categoryToString(it->second) << " and ";
        if (this->parkingOccupancy.find(it->first) == this->parkingOccupancy.end()) {
            cout << "is empty" << endl;
        } else {
            cout << "contains a vehicle ";
            cout << " with license plate " << this->parkingOccupancy[it->first].plate;
            cout << " belonging to " << this->parkingOccupancy[it->first].owner << endl;
        }
    }
}
