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
    for (auto r: this->roomNames) {
        if (r == name) {
            return; // The room already exists: do nothing
        }
    }
    this->roomNames.push_back(name);
}

// Task 3(b).  Implement this method
void Hotel::addGuest(string roomName, string guestName, string guestId) {
    bool roomExists = false;
    for (auto r: this->roomNames) {
        if (r == roomName) {
            roomExists = true;
            break;
        }
    }
    if (!roomExists) {
        return;
    }

    for (auto g: this->roomOccupancy) {
        if (g.second.id == guestId) {
            return; // The guestId is already in use
        }
    }

    if (this->roomOccupancy.find(roomName) == this->roomOccupancy.end()) {
        // The room is empty
        this->roomOccupancy[roomName] = {guestName, guestId};
    }
}

// Task 3(c).  Implement this method
void Hotel::findRoomByGuest(string guestName, string guestId) {
    for (auto r: this->roomNames) {
        if (this->roomOccupancy.find(r) == this->roomOccupancy.end()) {
            continue; // The room is empty
        }
        Guest g = this->roomOccupancy[r];

        bool match = true;
        if (guestName != "*") {
            match = (g.name == guestName);
        }
        if (guestId != "*") {
            match = match && (g.id == guestId);
        }
        if (match) {
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
