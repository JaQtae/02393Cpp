#include <iostream>
#include "ex03-library.h"

using namespace std;

int main() {
    GroceryList gl = GroceryList();

    cout << "Initial grocery list:" << endl;
    gl.display();

    cout << endl << "After adding cheddar:" << endl;
    gl.add("Cheddar", 500, "Not too mature");
    gl.display();

    cout << endl << "After adding more spinach:" << endl;
    gl.add("Spinach", 200, "Baby spinach if available");
    gl.display();

    cout << endl << "After adding more spinach:" << endl;
    gl.add("Spinach", 200, "Frozen is OK");
    gl.display();

    return 0;
}

