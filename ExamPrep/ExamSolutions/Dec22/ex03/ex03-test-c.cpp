#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    Locker locker = Locker();

    cout << "Initial locker occupancy:" << endl;
    locker.display();

    vector<string> v;

    cout << endl << "Package search result with an empty vector of recipients:" << endl;
    locker.findPackagesByRecipient(v);

    v.push_back("Edward");
    v.push_back("Claire");
    cout << endl << "Package search result with non-existent recipients:" << endl;
    locker.findPackagesByRecipient(v);

    v.push_back("Alice");
    cout << endl << "Package search result with one existing recipient:" << endl;
    locker.findPackagesByRecipient(v);

    v.insert(v.begin(), "Daisy");
    cout << endl << "Package search result with two existing recipients:" << endl;
    locker.findPackagesByRecipient(v);

    return 0;
}
