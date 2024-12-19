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

    bool parkingExists = false;
    
    for (auto r: this->parkingSpaces) {
        if(parkingSpaceID == r.first){
            if (category == r.second){
                parkingExists = true;
            }
        }
    }

    if(!parkingExists){
        // The specified parking space does not exist or is for a different category
        return;
    }

    if (this->parkingOccupancy.find(parkingSpaceID) != this->parkingOccupancy.end()) {
        // The parking space is occupied
        return;
    }

    this->parkingOccupancy[parkingSpaceID] = {plate, owner};
    return;
    
}

// Task 3(b).  Implement this method
void ParkingArea::leave(vector<string> plates)
{
    for (auto it2 = plates.begin(); it2 != plates.end(); it2++) {
        for (auto r: this->parkingOccupancy) {
            if(r.second.plate == *it2){
                this->parkingOccupancy.erase(r.first);
                break;
            }
        }
    }
}


// Task 3(c).  Implement this method
unsigned int ParkingArea::getEmptySpaces(Category category) {
    unsigned int count = 0;
    for (auto it = this->parkingSpaces.begin(); it != this->parkingSpaces.end(); it++) {
        if(it->second == category){
            if (this->parkingOccupancy.find(it->first) == this->parkingOccupancy.end()) {
                count++;
            }
        }
    }
    return count;
}

// Task 3(d).  Implement this method
void ParkingArea::findVehicles(vector<string> owners) {
    for (auto it = this->parkingSpaces.begin(); it != this->parkingSpaces.end(); it++) {
        if (this->parkingOccupancy.find(it->first) != this->parkingOccupancy.end()) {
            for (auto it2 = owners.begin(); it2 != owners.end(); it2++) {
                if (this->parkingOccupancy[it->first].owner == *it2){
                    cout << it->first << endl;
                }
            }
        }
    }
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
