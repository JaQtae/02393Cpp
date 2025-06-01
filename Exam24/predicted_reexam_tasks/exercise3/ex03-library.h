#ifndef EX03_LIBRARY_H_
#define EX03_LIBRARY_H_

#include <string>
#include <vector>
using namespace std;

enum Purpose { ADMINISTRATION, RESEARCH, LECTURE };

struct Building {
    string name;
    Purpose purpose;
    unsigned int landOccupation;
};

class Campus {
private:
    vector<Building> buildings;

public:
    void removeBuildingsByPurpose(Purpose p);
    void sortBuildingsByLand();
    bool canExpandCampus(unsigned int extraLand);
    double percentageOccupied();

    // For testing: add building
    void addBuilding(const Building& b);
    void printBuildings();
};

#endif /* EX03_LIBRARY_H_ */