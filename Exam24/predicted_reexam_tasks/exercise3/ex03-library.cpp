// Exercise 3: Campus predicted re-exam tasks
#include <vector>
#include <string>
#include <algorithm>
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
    void removeBuildingsByPurpose(Purpose p) {
        buildings.erase(remove_if(buildings.begin(), buildings.end(),
            [p](const Building &b) { return b.purpose == p; }), buildings.end());
    }

    void sortBuildingsByLand() {
        sort(buildings.begin(), buildings.end(),
            [](const Building &a, const Building &b) {
                return a.landOccupation < b.landOccupation;
            });
    }

    bool canExpandCampus(unsigned int extraLand) {
        unsigned int total = 0;
        for (const Building &b : buildings) total += b.landOccupation;
        return total + extraLand <= 10000;
    }

    double percentageOccupied() {
        unsigned int total = 0;
        for (const Building &b : buildings) total += b.landOccupation;
        return (100.0 * total) / 10000.0;
    }
};
