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
void Hotel::renameRoom(string oldName, string newName) {
    bool oldRoomExists = false;
    unsigned int oldRoomPosition = 0;
    bool newRoomExists = false;

    for (unsigned int i = 0; i < this->roomNames.size(); i++) {
        if (this->roomNames[i] == oldName) {
            oldRoomExists = true;
            oldRoomPosition = i;
        } else if (this->roomNames[i] == newName) {
            newRoomExists = true;
            break;
        }
    }
    if ((!oldRoomExists) || newRoomExists) {
        return;
    }
    
    // Update the list of room names
    this->roomNames[oldRoomPosition] = newName;

    // Update the room occupancy
    if (this->roomOccupancy.find(oldName) != this->roomOccupancy.end()) {
        this->roomOccupancy[newName] = this->roomOccupancy[oldName];
        this->roomOccupancy.erase(oldName);
    }
}

// Task 3(b).  Implement this method
void Hotel::removeGuest(string roomName, string guestName, string guestId) {
    if (this->roomOccupancy.find(roomName) == this->roomOccupancy.end()) {
        // The room is empty
        return;
    }
    Guest g = this->roomOccupancy[roomName];
    if ((g.name == guestName) && (g.id == guestId)) {
        this->roomOccupancy.erase(roomName);
    }
}

// Task 3(c).  Implement this method
void Hotel::findRoomByGuestId(vector<string> guestIds) {
    for (auto r: this->roomNames) {
        if (this->roomOccupancy.find(r) == this->roomOccupancy.end()) {
            // The room is empty
            continue;
        }
        for (auto id: guestIds) {
            if (this->roomOccupancy[r].id == id) {
                cout << r << endl;
            }
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
