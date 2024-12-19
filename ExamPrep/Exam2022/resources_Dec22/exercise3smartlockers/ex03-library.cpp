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
    // 
    // Loop over all lockerID's -> check if == lockerID. If found, return true. Else false.
    bool LockerExists = false;
    for (auto l: this->lockerIDs) {
        if (lockerID == l) {
            LockerExists = true;
        } 
    }
    // Cannot have this in the loop above. Do it globally. 
    if (!LockerExists) {
        return;
    }

    if (this->lockerOccupancy.find(lockerID) != this->lockerOccupancy.end()) {
        // Locker is occupied (It's NOT unoccupied)
        return;
    }
    // Update information of the locker.
    Package p = {sender, recipient, unlockCode};
    this->lockerOccupancy[lockerID] = p;
    return;
}

// Task 3(b).  Implement this method
void Locker::retrievePackage(string lockerID, int unlockCode) {
    // Write your code here
    for (auto i = this->lockerOccupancy.begin(); i != this->lockerOccupancy.end(); i++) {
        if (i->first == lockerID) { // lockerID matches
                if (i->second.unlockCode == unlockCode) { // unlockCode matches
            this->lockerOccupancy.erase(i); // Retrieve package
            break; // Exit
            }
        } 
    }
    return; // We didn't find a valid match
}

// Task 3(c).  Implement this method
void Locker::findPackagesByRecipient(vector<string> recipients) {
    // Write your code here
    // given colection of recipients
    // display ID(s) of locker(s) contained in recipients
    // Display one per line by following order in lockerIDs
    for (auto l : this->lockerIDs){ // for l in lockerIDs (NEEDS TO BE IN ORDER OF LOCKERID)
        // if it is occupied
        if (this->lockerOccupancy.find(l) != this->lockerOccupancy.end()) {
            for (auto r : recipients) { // Traverse recipients
                // check if it belongs to r in recipients
                if (this->lockerOccupancy[l].recipient == r) {
                    // print the lockerID
                    cout << l << endl;
                    break;
                }
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
