#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    Campus campus = Campus();

    cout << "Initial status:" << endl;
    campus.display();
    cout << endl;
    
    bool result = false;
    cout << "Adding building B501...";
    result = campus.buildNewBuilding("B501", ADMINISTRATION, 300);
    cout << (result ? "success" : "failed") << endl;
    cout << "Adding building B502...";
    result = campus.buildNewBuilding("B502", DEPARTMENT, 150);
    cout << (result ? "success" : "failed") << endl;
    cout << "Adding building B503...";
    result = campus.buildNewBuilding("B503", AUDITORIUM, 150);
    cout << (result ? "success" : "failed") << endl;
    
    cout << "Adding building B500 exceeding campus land occupation limits...";
    result = campus.buildNewBuilding("B500", AUDITORIUM, 200);
    cout << (result ? "success" : "failed") << endl;

    cout << endl;
    cout << "Current status:" << endl;
    campus.display();
    cout << endl;

    cout << "Names of buildings for administrative staff" << endl;
    campus.printBuildingNames(ADMINISTRATION);
    
    cout << "Names of buildings for students" << endl;
    campus.printBuildingNames(AUDITORIUM);
    
    cout << "Names of buildings for researchers" << endl;
    campus.printBuildingNames(DEPARTMENT);

    cout << endl;
    cout << "Repurposing building B402 as auditorium for students...";
    result = campus.repurposeBuilding("B402", AUDITORIUM);
    cout << (result ? "success" : "failed") << endl;
    
    cout << "Demolishing buildings B101 and B210...";
    vector<string> list;
    list.push_back("B101");
    list.push_back("B210");
    unsigned int freeLand = campus.demolishBuildings(list);
    cout << "freed " << freeLand << " units of land" << endl;

    cout << endl;
    cout << "Current status:" << endl;
    campus.display();

    return 0;
}
