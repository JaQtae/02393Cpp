#ifndef EX03_LIBRARY_H_
#define EX03_LIBRARY_H_

#include <string>
#include <vector>
#include <map>
using namespace std;

enum Category { CAR, MOTORBIKE, TRUCK };

struct Vehicle {
    string plate;
    string owner;
};

class ParkingArea {
private:
    map<string,Category> parkingSpaces;
    map<string,Vehicle> parkingOccupancy;
    
    //Existing
    string categoryToString(Category c);
public:
    ParkingArea();
    void park(string parkingSpaceID, string plate, string owner, Category category);
    unsigned int getEmptySpaces(Category category);
    void findVehicles(vector<string> owners);

    void leave(vector<string> plates);
    
    //Existing
    void display();
};

#endif /* EX03_LIBRARY_H_ */
