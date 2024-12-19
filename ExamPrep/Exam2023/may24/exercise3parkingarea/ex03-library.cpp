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
    // Vehicles leaving parking space
    // iterate over all vehicle plates in the input string
    for (const auto& plate : plates) { // for each plate in all vehicle plates
        // for parking space #first to parking space #last
        for (auto i = this->parkingOccupancy.begin(); i != this->parkingOccupancy.end(); i++) {
            // if the plate of the vehicle in the parking space 
            // is the same as the plate of the vehicle leaving

            // i is a a pointer to a pair of key-value pairs
            // i->first is the key, i->second is the value
            // i->second.plate is the plate of the vehicle in the parking space

            // FROM DEBUGGER: i
            // {first = "LYNGBY01", second = {plate = "AB123XY", owner = "Alice"}}
            if (i->second.plate == plate) {
                // remove the vehicle from the parking space
                this->parkingOccupancy.erase(i);
                break; // match found, exit loop
            }
        }
    }
}


// Task 3(c).  Implement this method
unsigned int ParkingArea::getEmptySpaces(Category category) {

    unsigned int count = 0; // counting empty parking spaces
    // iterate over all parking spaces
    // RANGE BASED FOR LOOP: don't need to manage index explicitly
    // for (element_type variable : container) {  <code>  }
    // Go through each element in container one by one.

    // equivalent to:
    //     for (size_t i = 0; i < this->parkingSpaces.size(); i++) {
    //     const auto& parkingSpace = this->parkingSpaces[i];
    //     }      
    for (const auto& parkingSpace : this->parkingSpaces) {
        // if Category of parking space is the one we query for

        if (parkingSpace.second == category) {
            // if this instance of the parking space is not found
            // add to empty counter
            if (this->parkingOccupancy.find(parkingSpace.first) == this->parkingOccupancy.end()) {
                count++;
            }
        }
    }

	return count;
}

// Task 3(d).  Implement this method
void ParkingArea::findVehicles(vector<string> owners) {
    // Map-struct is inherently sorted by key order.
    // Hence, it does not follow the order of parkingSpaces!


    for (const auto& parkingSpace : this->parkingSpaces) { // each parking space
        auto parkingSpaceID = parkingSpace.first; // get the ID
        auto it = this->parkingOccupancy.find(parkingSpaceID); // if space occupied

        if (it != this->parkingOccupancy.end()){ // if it is occupied  (NOT NOT EMPTY)
            for (const auto& owner : owners) { // for each owner in owners
                if (it->second.owner == owner) { // if parkingspace owner matches
                    cout << parkingSpaceID << endl; // print
                }
            }
        }

    }
    // The ordering issue arises because std::map in C++ is sorted by key according to
    // the comparison function (by default, it uses the < operator). 
    // This means that when you iterate over a std::map, the elements will be ordered by the keys,
    // not by the order in which they were inserted or the order in parkingSpaces.

    
    // Doesn't work since map is stored in key order, not in the order of parkingSpaces...
    // for (auto& owner: owners) {
    //     // Check all parking spaces
    //     for (auto& parkingSpace : this->parkingSpaces) {
    //         // If the parking space is occupied and has the queried owner value
    //         if (parkingOccupancy.find(parkingSpace.first) != parkingOccupancy.end() && parkingOccupancy[parkingSpace.first].owner == owner) {
    //             // print corresponding parkingSpaceID of owner
    //            cout << parkingSpace.first << endl; // parkingSpaceID
    //         }
    //     }
    // }
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
