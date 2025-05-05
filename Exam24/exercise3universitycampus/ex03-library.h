#ifndef EX03_LIBRARY_H_
#define EX03_LIBRARY_H_

#include <string>
#include <vector>
#include <map>
using namespace std;

enum Purpose { ADMINISTRATION, DEPARTMENT, AUDITORIUM };

struct Building {
    string name;
    Purpose purpose; 
    unsigned int landOccupation;
};

class Campus {
private:
    vector<Building> buildings;
    unsigned int land;
    
    //Existing
    string purposeToString(Purpose c);
public:
    Campus(void);
    bool buildNewBuilding(string name, Purpose purpose, unsigned int landOccupation);
    void printBuildingNames(Purpose purpose);
    bool repurposeBuilding(string name, Purpose newPurpose);
    unsigned int demolishBuildings(vector<string> buildingNames);
    
    //Existing
    void display();
};

#endif /* EX03_LIBRARY_H_ */
