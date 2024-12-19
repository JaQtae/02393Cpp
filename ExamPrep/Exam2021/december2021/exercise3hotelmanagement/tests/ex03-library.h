#ifndef EX03_LIBRARY_H_
#define EX03_LIBRARY_H_

#include <string>
#include <vector>
#include <map>
using namespace std;

struct Guest {
    string name;
    string id;
};

class Hotel {
private:
    vector<string> roomNames;
    map<string,Guest> roomOccupancy;
public:
    Hotel();
    void addRoom(string name);
    void addGuest(string roomName, string guestName, string guestId);
    void findRoomByGuest(string guestName, string guestId);
    void display();
};

#endif /* EX03_LIBRARY_H_ */
