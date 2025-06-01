#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    Campus c;

    c.addBuilding({"Main Admin", ADMINISTRATION, 1500});
    c.addBuilding({"Physics Lab", RESEARCH, 2500});
    c.addBuilding({"Chemistry Lab", RESEARCH, 3000});
    c.addBuilding({"Auditorium", LECTURE, 2000});
    c.addBuilding({"Annex", ADMINISTRATION, 800});

    cout << "Initial buildings:" << endl;
    c.printBuildings();

    cout << "\nRemoving RESEARCH buildings..." << endl;
    c.removeBuildingsByPurpose(RESEARCH);
    c.printBuildings();

    cout << "\nSorting buildings by land occupation:" << endl;
    c.sortBuildingsByLand();
    c.printBuildings();

    cout << "\nCan expand with 2000 land units? " 
         << (c.canExpandCampus(2000) ? "Yes" : "No") << endl;

    cout << "Can expand with 7000 land units? "
         << (c.canExpandCampus(7000) ? "Yes" : "No") << endl;

    cout << "\nCurrent percentage occupied: " 
         << c.percentageOccupied() << "%" << endl;

    return 0;
}