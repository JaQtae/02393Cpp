#include <iostream>
#include <algorithm>
#include "ex03-library.h"
using namespace std;

// Do not modify
string Campus::purposeToString(Purpose c)
{
    switch (c)
    {
    case ADMINISTRATION:
        return "administrative staff";
    case DEPARTMENT:
        return "researchers";
    case AUDITORIUM:
        return "students";
    default:
        return "";
    }
}

// Do not modify
Campus::Campus() {
    
    this->land = 2000;
    this->buildings.push_back({"B101", ADMINISTRATION, 300});
    this->buildings.push_back({"B402", ADMINISTRATION, 150});
    this->buildings.push_back({"B324", DEPARTMENT, 150});
    this->buildings.push_back({"B210", DEPARTMENT, 200});
    this->buildings.push_back({"B116", AUDITORIUM, 250});
    this->buildings.push_back({"B303", AUDITORIUM, 150});
    
}

// Task 3(a).  Implement this method
bool Campus::buildNewBuilding(string name, Purpose purpose, unsigned int landOccupation) {

    // (a) Check if the building already exists
    for (size_t i = 0; i < this->buildings.size(); i++) {
        if (this->buildings[i].name == name) {
            return false; // Building already exists
        }
    }

    // Can also be done as
    //      for (const Building &b : buildings) {
    //      if (b.name == name) return false;
    //      }
    //      for (const Building &b : buildings) {
    //      total += b.landOccupation;
    //      }

    // (b.1) Check if the new building + all others > 90% of Campus
        // Compute total land
    unsigned int total = 0;
    for (size_t i = 0; i < this->buildings.size(); i++) {
        total += buildings[i].landOccupation; // Running total of land occupation
    }
        // Check condition of 90%
    if (total + landOccupation > (this->land * 0.9)) { // If new building + all others > 90% of Campus
        return false; // Not enough land available
    }
    // (b.2) If not return true and update the vector of buildings.
        // Update buildings vector
    this->buildings.push_back({name, purpose, landOccupation}); // Information input
    return true; // Building added successfully
    
}

// Task 3(b).  Implement this method
// void Campus::printBuildingNames(Purpose purpose){
    // They both live under #include <algorithm>
    // sort() is unstable -- does not preserve relative order of equal elements
    // stable_sort() is stable -- preserves relative order of equal elements
        // Direct/Manual way to do this:
        // Step 1: collect matching buildings
        // vector<Building> filtered;
        // for (const Building &b : buildings) {
        //     if (b.purpose == purpose) {
        //         filtered.push_back(b);
        //     }
        // }

        // Step 2: manually sort filtered list by landOccupation (stable)
        // for (size_t i = 0; i < filtered.size(); ++i) {
        //     for (size_t j = i + 1; j < filtered.size(); ++j) {
        //         if (filtered[j].landOccupation < filtered[i].landOccupation) {
                       // Swap if j is smaller than i (preserves order of equal elements)
        //             Building temp = filtered[i];
        //             filtered[i] = filtered[j];
        //             filtered[j] = temp;
        //         }
        //     }
        // }

        // Step 3: print names
        // for (const Building &b : filtered) {
        //     cout << b.name << endl;
// }
void Campus::printBuildingNames(Purpose purpose) {
    // collect matching buildings
    vector<Building> filtered;
    for (const Building &b : buildings) {
        if (b.purpose == purpose) filtered.push_back(b);
    }
    // sort by landOccupation ascending, stable for equal sizes
    stable_sort(filtered.begin(), filtered.end(),
        [](const Building &a, const Building &b) {
            return a.landOccupation < b.landOccupation;
        }
    );
    // print names
    for (const Building &b : filtered) {
        cout << b.name << endl;
    }
}

// Task 3(c).  Implement this method
bool Campus::repurposeBuilding(string name, Purpose newPurpose) {
    return false;

}

// Task 3(d).  Implement this method
unsigned int Campus::demolishBuildings(vector<string> names) {
    return 0;
}

// Do not modify
void Campus::display() {
    cout << "The campus owns " << this->land << " units of land." << endl;
    for (auto it = this->buildings.begin(); it != this->buildings.end(); it++) {
        cout << "Building " << it->name << " ";
        cout << "is for " << purposeToString(it->purpose) << " and it ";
        cout << "occupies " << it->landOccupation << " units of land." ;
        cout << endl;
    }
}
