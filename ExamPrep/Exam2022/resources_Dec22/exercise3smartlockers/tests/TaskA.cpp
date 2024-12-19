#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    Locker locker = Locker();

    cout << "Initial locker occupancy:" << endl;
    locker.display();

    // This should always succeed
    locker.putPackage("LYNGBY04", "Alice", "Bob", 951);
    cout << endl << "After putting a package from Alice to Bob inside an empty locker:" << endl;
    locker.display();

    locker.putPackage("LYNGBY02", "Claire", "Daisy", 753);
    cout << endl << "After putting a package from Claire to Daisy inside an already occupied locker:" << endl;
    locker.display();

    locker.putPackage("LYNGBY07", "Bob", "Claire", 147);
    cout << endl << "After putting a package from Bob to Claire inside a non-existing locker:" << endl;
    locker.display();

    locker.putPackage("LYNGBY06", "Daisy", "Bob", 963);
    cout << endl << "After putting a package from Daisy to Bob inside an empty locker:" << endl;
    locker.display();

    return 0;
}
