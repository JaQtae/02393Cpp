#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    Campus campus = Campus();

    cout << "Initial status:" << endl;
    campus.display();
    cout << endl;
    
    bool result = false;
    cout << "Repurposing building B101 as auditorium for students...";
    result = campus.repurposeBuilding("B101", AUDITORIUM);
    cout << (result ? "success" : "failed") << endl;
    
    cout << "Repurposing building B210 as administration for administrative staff...";
    result = campus.repurposeBuilding("B210", ADMINISTRATION);
    cout << (result ? "success" : "failed") << endl;
    
    cout << "Repurposing building B303 as department for researchers...";
    result = campus.repurposeBuilding("B303", DEPARTMENT);
    cout << (result ? "success" : "failed") << endl;
    
    cout << endl;
    cout << "Current status:" << endl;
    campus.display();
    cout << endl;

    cout << "Repurposing building B210 back to department for researchers...";
    result = campus.repurposeBuilding("B210", DEPARTMENT);
    cout << (result ? "success" : "failed") << endl;
    
    cout << "Repurposing non-existing building B500 as auditorium for students...";
    result = campus.repurposeBuilding("B500", AUDITORIUM);
    cout << (result ? "success" : "failed") << endl;

    cout << "Repurposing building B324 as department for researchers...";
    result = campus.repurposeBuilding("B324", DEPARTMENT);
    cout << (result ? "success" : "failed") << endl;
    
    cout << endl;
    cout << "Current status:" << endl;
    campus.display();
    cout << endl;

    return 0;
}
