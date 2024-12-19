#ifndef EX03_LIBRARY_H_
#define EX03_LIBRARY_H_

#include <string>
#include <vector>
#include <map>
using namespace std;

struct Package {
    string sender;
    string recipient;
    int unlockCode; 
};

class Locker {
private:
    vector<string> lockerIDs;
    map<string,Package> lockerOccupancy;
public:
    Locker();
    void putPackage(string lockerID, string sender, string recipient, int unlockCode);
    void retrievePackage(string lockerID, int unlockCode);
    void findPackagesByRecipient(vector<string> recipients);
    void display();
};

#endif /* EX03_LIBRARY_H_ */
