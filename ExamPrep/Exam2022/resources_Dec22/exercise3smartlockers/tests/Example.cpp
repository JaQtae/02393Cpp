#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    Locker locker = Locker();

    cout << "Initial locker occupancy:" << endl;
    locker.display();

    locker.putPackage("LYNGBY04", "Alice", "Bob", 951);
    cout << endl << "After putting a package from Alice to Bob inside an empty locker:" << endl;
    locker.display();

    locker.retrievePackage("LYNGBY01", 1234);
    cout << endl << "After retrieving a package:" << endl;
    locker.display();

    cout << endl << "Package(s) addressed to Bob or Daisy:" << endl;
    vector<string> v;
    v.push_back("Bob");
    v.push_back("Daisy");
    locker.findPackagesByRecipient(v);

    return 0;
}
