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
    void renameRoom(string oldName, string newName);
    void removeGuest(string roomName, string guestName, string guestId);
    void findRoomByGuestId(vector<string> guestIds);
    void display();
};

#endif /* EX03_LIBRARY_H_ */
