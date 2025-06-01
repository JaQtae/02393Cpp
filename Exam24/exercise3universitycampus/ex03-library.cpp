#include <iostream>
#include <algorithm>
#include <unordered_set> // It's a part of std!
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

// -------- HELPER FUNCTIONS ---------- //
// Returns the index of the building named 'name' in 'builds', or -1 if not found.
static int findBuildingIndex(const vector<Building> &builds, const string &name) {
    for (size_t i = 0; i < builds.size(); ++i) {
        if (builds[i].name == name) {
            return (int)i;
        }
    }
    return -1;
}
// Returns the sum of landOccupation for every Building in 'builds'.
static unsigned int totalLandUsed(const vector<Building> &builds) {
    unsigned int sum = 0;
    for (const Building &b : builds) {
        sum += b.landOccupation;
    }
    return sum;
}
// Returns true if (used land + newSize) ≤ 90% of campusLand.
static bool canAddBuilding(const vector<Building> &builds, unsigned int campusLand, unsigned int newSize){
    unsigned int used = totalLandUsed(builds);
    // Compute 90% of campusLand (integer math):
    unsigned int ninetyPercent = (campusLand * 90) / 100;
    return (used + newSize) <= ninetyPercent;
}
// Returns true if after removing removeSize from current usage, 
// the occupied land is still ≥ 10% of campusLand.
static bool canRemoveBuilding(const vector<Building> &builds,unsigned int campusLand,unsigned int removeSize){
    unsigned int used = totalLandUsed(builds);
    if (removeSize > used) {
        // Something’s wrong: can’t remove more land than currently used.
        return false;
    }
    unsigned int afterRemoval = used - removeSize;
    // At least 10% of campusLand should remain occupied:
    unsigned int tenPercent = (campusLand * 10) / 100;
    return afterRemoval >= tenPercent;
}
// Sorts 'builds' in place by landOccupation ascending (smallest first), stable.
static void sortBuildingsAscending(vector<Building> &builds) {
    for (size_t i = 0; i + 1 < builds.size(); ++i) {
        for (size_t j = i + 1; j < builds.size(); ++j) {
            if (builds[j].landOccupation < builds[i].landOccupation) {
                swap(builds[i], builds[j]);
            }
        }
    }
}
// If you need descending (largest first), just flip the comparison:
static void sortBuildingsDescending(vector<Building> &builds) {
    for (size_t i = 0; i + 1 < builds.size(); ++i) {
        for (size_t j = i + 1; j < builds.size(); ++j) {
            if (builds[j].landOccupation > builds[i].landOccupation) {
                swap(builds[i], builds[j]);
            }
        }
    }
}
// Erases any Building whose name is in the set `toRemove`. Returns total land freed.
// Handy if you get something like demolishBuildings()
static unsigned int removeBuildingsByNames(vector<Building> &builds,const vector<string> &names) {
    unordered_set<string> nameSet(names.begin(), names.end());
    unsigned int freed = 0;
    auto it = builds.begin();
    while (it != builds.end()) {
        if (nameSet.count(it->name)) {
            freed += it->landOccupation;
            it = builds.erase(it);
        } else {
            ++it;
        }
    }
    return freed;
}
// Returns a NEW vector containing only those buildings whose purpose == p.
// Combine with sortBuildingsAscending on the returned vector if asked something like
// "print building names for purpose, sorted by their landOccupation"
static vector<Building> filterBuildingsByPurpose(const vector<Building> &builds, Purpose p) {
    vector<Building> result;
    for (const Building &b : builds) {
        if (b.purpose == p) {
            result.push_back(b);
        }
    }
    return result;
}





// Task 3(a).  Implement this method
bool Campus::buildNewBuilding(string name, Purpose purpose, unsigned int landOccupation) {
    // (a)
    unsigned int total_land = 0;
    for (auto it = this->buildings.begin(); it != this->buildings.end(); it++) {
        if (it->name == name) {
            return false;
        }
        total_land += it->landOccupation;
    }
    // (b)
    if ((total_land + landOccupation) > ((this->land * 90) / 100)) {
        return false;
    }
    // Update
    this->buildings.push_back({name, purpose, landOccupation});
    return true; // Building added successfully
}

// task 3(b).  Implement this method
void Campus::printBuildingNames(Purpose purpose) {
    auto filtered_builds = filterBuildingsByPurpose(this->buildings, purpose);
    // Filters on the landOccupation of each building
    sortBuildingsAscending(filtered_builds); // void doesnt return anything
    for (auto b : filtered_builds) {
        cout << b.name << endl;
    }
}

// Task 3(c).  Implement this method
bool Campus::repurposeBuilding(string name, Purpose newPurpose) {
    for (Building &b : buildings) { // For each building
        if (b.name == name) { // name matches
            if (b.purpose == newPurpose) return false; // name good, purpose is same, so bad
            b.purpose = newPurpose; // Overwrite
            return true; 
        }
    }

    return false;
}

// Task 3(d).  Implement this method
unsigned int Campus::demolishBuildings(vector<string> names) {
    unsigned int freed = 0;
    unordered_set<string> nameSet(names.begin(), names.end());
    auto it = buildings.begin();
    while (it != buildings.end()) {
        if (nameSet.count(it->name)) {
            freed += it->landOccupation;
            it = buildings.erase(it);
        } else {
            ++it;
        }
    }
    return freed;

//     unsigned int freed = 0;
//     for (auto it = buildings.begin(); it != buildings.end(); /* see below */) {
//         // Check if buildings[it]’s name appears in the “names” list:
//         bool toDelete = false;
//         for (const string &candidate : names) {
//             if (candidate == it->name) {
//                 toDelete = true;
//                 break;
//             }
//         }
//         if (toDelete) {
//             freed += it->landOccupation;
//             it = buildings.erase(it);  // erase returns the next iterator
//         } else {
//             ++it;
//         }
//     }
//     return freed;
// }
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
