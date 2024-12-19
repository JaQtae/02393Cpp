#include <iostream>
#include "ex03-library.h"

using namespace std;

int main() {
    GroceryList gl = GroceryList();

    cout << "Initial grocery list:" << endl;
    gl.display();

    cout << endl << "After removing some spinach:" << endl;
    if (gl.remove("Spinach", 200)) {
        gl.display();
    } else {
        cout << "FAILED! (this should not happen)" << endl;
    }

    cout << endl << "After removing more spinach:" << endl;
    if (gl.remove("Spinach", 100)) {
        gl.display();
    } else {
        cout << "FAILED! (this should not happen)" << endl;
    }

    cout << endl << "Trying to remove even more spinach:" << endl;
    if (gl.remove("Spinach", 100)) {
        gl.display();
    } else {
        cout << "FAILED! (this is correct)" << endl;
    }

    cout << endl << "Trying to remove cheddar:" << endl;
    if (gl.remove("Cheddar", 100)) {
        gl.display();
    } else {
        cout << "FAILED! (this is correct)" << endl;
    }

    return 0;
}
