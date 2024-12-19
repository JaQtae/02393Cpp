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
    this->parkingOccupancy["LYNGBY01"] = {"AB123XY", "Alice", CAR};

    this->parkingSpaces["LYNGBY02"] = CAR;
    this->parkingOccupancy["LYNGBY02"] = {"CD987WQ", "Bob", CAR};

    this->parkingSpaces["LYNGBY03"] = CAR;
    this->parkingOccupancy["LYNGBY03"] = {"EF456SA", "Claire", MOTORBIKE};

    this->parkingSpaces["LYNGBY04"] = CAR;

    this->parkingSpaces["LYNGBY05"] = TRUCK;
    this->parkingOccupancy["LYNGBY05"] = {"GH102MN", "Daisy", TRUCK};

    this->parkingSpaces["LYNGBY06"] = MOTORBIKE;
}

// Task 3(a).  Implement this method
void ParkingArea::park(string parkingSpaceID, string plate, string owner, Category category) {

    bool parkingExists = false;
    
    for (auto r: this->parkingSpaces) {
        if(parkingSpaceID == r.first){
            parkingExists = true;
        }
    }

    if(!parkingExists){
        // The specified parking space does not exist
        return;
    }

    if (this->parkingOccupancy.find(parkingSpaceID) != this->parkingOccupancy.end()) {
        // The parking space is occupied
        return;
    }

    this->parkingOccupancy[parkingSpaceID] = {plate, owner, category};
    return;
    
}

// Task 3(b).  Implement this method
void ParkingArea::leave(string plate)
{
    for (auto r: this->parkingOccupancy) {
        if(r.second.plate == plate){
            this->parkingOccupancy.erase(r.first);
            break;
        }
    }
}


// Task 3(c).  Implement this method
void ParkingArea::findMisplacedVehicles() {
    for (auto it = this->parkingSpaces.begin(); it != this->parkingSpaces.end(); it++) {
        if (this->parkingOccupancy.find(it->first) != this->parkingOccupancy.end()) {
            if(this->parkingOccupancy[it->first].category != it->second){
                cout << parkingOccupancy[it->first].plate << endl;
            }
        }
    }
}

// Task 3(d).  Implement this method
void ParkingArea::findVehicles(vector<string> plates) {
    for (auto it = this->parkingSpaces.begin(); it != this->parkingSpaces.end(); it++) {
        if (this->parkingOccupancy.find(it->first) != this->parkingOccupancy.end()) {
            for (auto it2 = plates.begin(); it2 != plates.end(); it2++) {
                if (this->parkingOccupancy[it->first].plate == *it2){
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
            cout << "contains a " << categoryToString(this->parkingOccupancy[it->first].category);
            cout << " with license plate " << this->parkingOccupancy[it->first].plate;
            cout << " belonging to " << this->parkingOccupancy[it->first].owner << endl;
        }
    }
}
