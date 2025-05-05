#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    Campus campus = Campus();

    cout << "Initial status:" << endl;
    campus.display();
    cout << endl;
    
    cout << "Names of buildings for administrative staff" << endl;
    campus.printBuildingNames(ADMINISTRATION);
    
    cout << "Names of buildings for students" << endl;
    campus.printBuildingNames(AUDITORIUM);
    
    cout << "Names of buildings for researchers" << endl;
    campus.printBuildingNames(DEPARTMENT);

    return 0;
}
