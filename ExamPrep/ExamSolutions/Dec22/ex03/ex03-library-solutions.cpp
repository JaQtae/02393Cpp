#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
Locker::Locker() {
    this->lockerIDs.push_back("LYNGBY01");
    this->lockerOccupancy["LYNGBY01"] = {"Alice", "Daisy", 1234};

    this->lockerIDs.push_back("LYNGBY02");
    this->lockerOccupancy["LYNGBY02"] = {"Claire", "Alice", 567};

    this->lockerIDs.push_back("LYNGBY03");
    this->lockerOccupancy["LYNGBY03"] = {"Daisy", "Bob", 890};

    this->lockerIDs.push_back("LYNGBY04");

    this->lockerIDs.push_back("LYNGBY05");
    this->lockerOccupancy["LYNGBY05"] = {"Bob", "Daisy", 159};

    this->lockerIDs.push_back("LYNGBY06");
}

// Task 3(a).  Implement this method
void Locker::putPackage(string lockerID, string sender, string recipient, int unlockCode) {

    bool lockerExists = false;
    for (auto r: this->lockerIDs) {
        if(lockerID == r){
            lockerExists = true;
        }
    }

    if(!lockerExists){
        // The specified locker does not exist
        return;
    }

    if (this->lockerOccupancy.find(lockerID) != this->lockerOccupancy.end()) {
        // The locker is occupied
        return;
    }

    this->lockerOccupancy[lockerID] = {sender, recipient, unlockCode};
    return;
    
}

// Task 3(b).  Implement this method
void Locker::retrievePackage(string lockerID, int unlockCode) {
    if (this->lockerOccupancy.find(lockerID) == this->lockerOccupancy.end()) {
        // The locker is empty, or it does not exist
        return;
    }
    Package p = this->lockerOccupancy[lockerID];
    if ((p.unlockCode == unlockCode)) {
        this->lockerOccupancy.erase(lockerID);
    } else {
        //incorrect unlock code
        return;
    }
}

// Task 3(c).  Implement this method
void Locker::findPackagesByRecipient(vector<string> recipients) {
    for (auto r: this->lockerIDs) {
        if (this->lockerOccupancy.find(r) == this->lockerOccupancy.end()) {
            // The locker is empty
            continue;
        }
        for (auto id: recipients) {
            if (this->lockerOccupancy[r].recipient == id) {
                cout << r << endl;
            }
        }
    }
}

// Do not modify
void Locker::display() {
    for (auto it = this->lockerIDs.begin(); it != this->lockerIDs.end(); it++) {
        cout << "Locker '" << *it << "' ";
        if (this->lockerOccupancy.find(*it) == this->lockerOccupancy.end()) {
            cout << "is empty" << endl;
        } else {
            cout << "contains a package from " << this->lockerOccupancy[*it].sender;
            cout << " to " << this->lockerOccupancy[*it].recipient;
            cout << " (unlock code: " << this->lockerOccupancy[*it].unlockCode << ")" << endl;
        }
    }
}
