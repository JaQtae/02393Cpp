#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
Hotel::Hotel() {
    this->roomNames.push_back("Daisy");
    this->roomOccupancy["Daisy"] = {"Alan Smithee", "xyz890"};

    this->roomNames.push_back("Geranium");

    this->roomNames.push_back("Lotus");
    this->roomOccupancy["Lotus"] = {"Kathryn Bigelow", "456abc"};

    this->roomNames.push_back("Orchid");
    this->roomOccupancy["Orchid"] = {"Alan Smithee", "abc123"};

    this->roomNames.push_back("Tulip");
    this->roomOccupancy["Tulip"] = {"Denis Villeneuve", "123xyz"};
}

// Task 3(a).  Implement this method
void Hotel::addRoom(string name) {
    // Write your code here
    // Objective is to add 'name' to the end of roomNames if not found

    // #include <algorithm> has a find() function for vectors.
    // if ( find(roomNames.begin(), roomNames.end(), name) == roomNames.end()) {
    //     roomNames.push_back(name);
    // }

    // If we dont use that, see under or Exam 22:
    for (auto r : this->roomNames) {
        if (r == name) {
            return;
        }
    }
    this->roomNames.push_back(name);
    // bool name_found = false;
    // for (size_t i=0; i < this->roomNames.size(); i++) {
    //     if (this->roomNames[i] == name){
    //         name_found = true;
    //         break;
    //     }
    // }
    // if (!name_found){
    //     this->roomNames.push_back(name);
    // }

}

// Task 3(b).  Implement this method
void Hotel::addGuest(string roomName, string guestName, string guestId) {
    // Write your code here

    // Check if room exists:
    bool exists = false;
    for (auto r : this->roomNames) {
        if (r == roomName) {
            exists = true;
            break; // Room exists.
        }
    }
    if (!exists) {
        return; // Doesn't exist, do nothing.
    }

    // Check all occupied rooms if they have the guestId
    for (auto g : this->roomOccupancy) {
        // g -> map(name, >id<) -> second.id == guestId?
        if (g.second.id == guestId) {
            return; // Do nothing. No duplicates!
        }
    }

    // Otherwise, if empty room:
    if (this->roomOccupancy.find(roomName) == this->roomOccupancy.end()) {
        // Insert information regarding guest "checking in"
        this->roomOccupancy[roomName] = {guestName, guestId}; 
    }

}

// Task 3(c).  Implement this method
void Hotel::findRoomByGuest(string guestName, string guestId) {
    // Write your code here
    for (auto r : this->roomNames) {
        if (this->roomOccupancy.find(r) == this->roomOccupancy.end()) {
            // room is empty
            continue; // Need to print rest
        }
        Guest g = this->roomOccupancy[r]; // Occupied room information

        bool match = true; // Wildcard * matches ANY name and id
        
        if (guestName != "*") { // if not Wildcard *
            match = (g.name == guestName); // match found
        }
        if (guestId != "*") {
            // name matched above AND id also matches
            match = match && (g.id == guestId);
        }
        if (match) { // Name and id matches anything (or above nonwildcards)
            cout << r << endl;
        }
    }
}

// Do not modify
void Hotel::display() {
    for (auto it = this->roomNames.begin(); it != this->roomNames.end(); it++) {
        cout << "Room '" << *it << "' is ";
        if (this->roomOccupancy.find(*it) == this->roomOccupancy.end()) {
            cout << "empty" << endl;
        } else {
            cout << "occupied by " << this->roomOccupancy[*it].name;
            cout << " (id: " << this->roomOccupancy[*it].id << ")" << endl;
        }
    }
}
