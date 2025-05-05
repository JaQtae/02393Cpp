#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    Campus campus = Campus();

    cout << "Initial status:" << endl;
    campus.display();
    cout << endl;

    cout << "Demolishing buildings B101 and B210...";
    vector<string> list;
    list.push_back("B101");
    list.push_back("B210");
    unsigned int freeLand = campus.demolishBuildings(list);
    cout << "freed " << freeLand << " units of land" << endl;

    cout << endl;
    cout << "Current status:" << endl;
    campus.display();
    cout << endl;

    cout << "Demolishing buildings B101 and B210 again...";
    freeLand = campus.demolishBuildings(list);
    cout << "freed " << freeLand << " units of land" << endl;

    cout << endl;
    cout << "Current status:" << endl;
    campus.display();
    cout << endl;

    cout << "Demolishing building B402 and non-existent building B403 at once...";
    list.clear();
    list.push_back("B402");
    list.push_back("B403");
    freeLand = campus.demolishBuildings(list);
    cout << "freed " << freeLand << " units of land" << endl;

    cout << endl;
    cout << "Current status:" << endl;
    campus.display();
    cout << endl;

    cout << "Demolishing non-existent buildings B500 and B501...";
    list.clear();
    list.push_back("B500");
    list.push_back("B501");
    freeLand = campus.demolishBuildings(list);
    cout << "freed " << freeLand << " units of land" << endl;

    cout << endl;
    cout << "Current status:" << endl;
    campus.display();
    cout << endl;
    
    cout << "Demolishing building B116 twice at once...";
    list.clear();
    list.push_back("B116");
    list.push_back("B116");
    freeLand = campus.demolishBuildings(list);
    cout << "freed " << freeLand << " units of land" << endl;

    cout << endl;
    cout << "Current status:" << endl;
    campus.display();
    cout << endl;

    return 0;
}
