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

    cout << endl << "After removing some spinach:" << endl;
    if (gl.remove("Spinach", 200)) {
        gl.display();
    } else {
        cout << "FAILED! (this should not happen)" << endl;
    }

    cout << endl << "After copying salmon into haddock:" << endl;
    if (gl.copyEntry("Salmon", "Haddock")) {
        gl.display();
    } else {
        cout << "FAILED! (this should not happen)" << endl;
    }

    return 0;
}
