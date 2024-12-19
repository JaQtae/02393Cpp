#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    Locker locker = Locker();

    cout << "Initial locker occupancy:" << endl;
    locker.display();

    locker.retrievePackage("LYNGBY03",890);
    cout << endl << "After retrieving a package from locker 'LYNGBY03':" << endl;
    locker.display();

    locker.retrievePackage("LYNGBY09",159);
    cout << endl << "After retrieving a package from non-existing locker 'LYNGBY09':" << endl;
    locker.display();

    locker.retrievePackage("LYNGBY01",1233);
    cout << endl << "After retrieving a package from locker 'LYNGBY01' with wrong unlock code:" << endl;
    locker.display();

    locker.retrievePackage("LYNGBY04",890);
    cout << endl << "After retrieving a package from empty locker 'LYNGBY04':" << endl;
    locker.display();

    locker.retrievePackage("LYNGBY05",159);
    cout << endl << "After retrieving a package from locker 'LYNGBY05':" << endl;
    locker.display();

    return 0;
}
