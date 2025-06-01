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
    // Check if parkingSpaceID is not in parkingSpaces; do nothing
    bool parkingExists = false;
    
    for (auto r: this->parkingSpaces) {
        if(parkingSpaceID == r.first){
            parkingExists = true;
        }
    }

    if(!parkingExists){
        return;   // The specified parking space does not exist
    }

    if (this->parkingOccupancy.find(parkingSpaceID) != this->parkingOccupancy.end()) {
        return;// The parking space is occupied
    }

    this->parkingOccupancy[parkingSpaceID] = {plate, owner, category}; // Update stuff
    return;
    

}

// Task 3(b).  Implement this method
void ParkingArea::leave(string plate)
{
    for (auto r: this->parkingOccupancy) {
        if(r.second.plate == plate) {
            this->parkingOccupancy.erase(r.first);
            break;
        }
    }
}


// Task 3(c).  Implement this method
void ParkingArea::findMisplacedVehicles() {
    // For each parkingspace, figure out if it is occupied by something
    // If it is occupied, figure out the category and check if it is what it initially was called as
    // print per line what license plate is in that faulty spot
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
        // For all parking spaces
        for (auto plate : plates) { // For each plate in plates input
            if (this->parkingOccupancy[it->first].plate == plate ) { // if the parkingspace is occupied by a matching plate
                cout << it->first << endl; // Display the psID
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
