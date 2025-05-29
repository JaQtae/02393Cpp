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
    // (1) check that pSID is not in pS, ie. its nullptr (i think)
    if (this->parkingSpaces.find(parkingSpaceID) == this->parkingSpaces.end()) {
        return; // do nothing
    }
    // (2.1)
    if (parkingSpaces[parkingSpaceID] != category) { // mismatch of category with parking space allocation
        return; // do nothing
    }
    // (2.2.1) // Already occupied?
    if (this->parkingOccupancy.find(parkingSpaceID) != this->parkingOccupancy.end()){
        return; // do nothing
    }
    // (2.2.2) It's not occupied, so we update
    Vehicle v = {plate, owner};
    this->parkingOccupancy[parkingSpaceID] = v;
}

// Task 3(b).  Implement this method
void ParkingArea::leave(vector<string> plates) {
    // avoids unnecessary copying with const auto&
    for (const auto& plate : plates) { // each plate in all plates, e.g. "AB12345" one at a time
        for (auto i = this->parkingOccupancy.begin(); i != this->parkingOccupancy.end(); i++ ){
            // i iterator points to key-value pair in the map, e.g. i->first is the space, 
            //          i->second is a Vehicle, which in turn has plate and owner attributes!
            if (i->second.plate == plate) {
                this->parkingOccupancy.erase(i); // remove entire entry in map if true
                break; // Exit loop, or iterator would lead to invalidater iterator, (and plates are assumed unique)
                //          since erase() modifies the original container!!!
            }
        }
    }
}


// Task 3(c).  Implement this method
unsigned int ParkingArea::getEmptySpaces(Category category) {
    unsigned int count_category = 0; // Count number of spaces available for category vehicle
    for (const auto& parkingSpace : this->parkingSpaces) { // For each parking space in current instance of parkingSpaces
        if (parkingSpace.second == category){ // matches category, but is it empty?
            if (this->parkingOccupancy.find(parkingSpace.first) == this->parkingOccupancy.end()){
                count_category++; // Found a space 
            }
        }
    }
	return count_category;
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
