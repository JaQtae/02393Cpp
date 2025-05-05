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
    result = campus.buildNewBuilding("B501", DEPARTMENT, 200);
    cout << (result ? "success" : "failed") << endl;
    cout << "Adding building B502...";
    result = campus.buildNewBuilding("B502", DEPARTMENT, 150);
    cout << (result ? "success" : "failed") << endl;
    cout << "Adding building B503...";
    result = campus.buildNewBuilding("B503", ADMINISTRATION, 100);
    cout << (result ? "success" : "failed") << endl;

    cout << endl;
    cout << "Current status:" << endl;
    campus.display();
    cout << endl;
    
    cout << "Adding building B101 which already exists...";
    result = campus.buildNewBuilding("B101", AUDITORIUM, 150);
    cout << (result ? "success" : "failed") << endl;

    cout << "Adding building B500 exceeding campus land occupation limits...";
    result = campus.buildNewBuilding("B500", AUDITORIUM, 200);
    cout << (result ? "success" : "failed") << endl;

    cout << endl;
    cout << "Current status:" << endl;
    campus.display();
    cout << endl;
    
    cout << "Adding building B600...";
    result = campus.buildNewBuilding("B600", AUDITORIUM, 150);
    cout << (result ? "success" : "failed") << endl;

    cout << endl;
    cout << "Current status:" << endl;
    campus.display();
    cout << endl;
    
    return 0;
}
