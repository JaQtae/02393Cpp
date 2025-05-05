#include <iostream>
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

    bool buildingExists = false;
    unsigned int total = 0;
    for (size_t i = 0; i < this->buildings.size(); i++) {
        if (this->buildings[i].name == name){
            buildingExists = true;
            break;
        }
        total += buildings[i].landOccupation; // Running total of land occupation
    }
    if (buildingExists) {
        return false;
    }

    if (total+landOccupation > ((this->land/100) * 90)) { // If new building + all others > 90% of Campus
        return false;
    } else { // Otherwise add it to the end of buildings.
        this->buildings.push_back({name, purpose, landOccupation}); // Information input
        return true;
    }

    
}

// Task 3(b).  Implement this method
void Campus::printBuildingNames(Purpose purpose){

    for (auto it = this->buildings.begin(); it != this->buildings.end(); it++) {
        if (it->purpose == purpose) {
            cout << it->name << endl; // I need to do the sorting too..
        }
    }
}

// Task 3(c).  Implement this method
bool Campus::repurposeBuilding(string name, Purpose newPurpose) {


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
