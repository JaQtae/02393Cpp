#include <iostream>
#include <string>
#include "ex03-library.h"

using namespace std;

int main() {
    GroceryList gl = GroceryList();

    cout << "Initial grocery list:" << endl;
    gl.display();

    cout << endl << "After copying spinach into baby spinach:" << endl;
    if (gl.copyEntry("Spinach", "Baby spinach")) {
        gl.display();
    } else {
        cout << "FAILED! (this should not happen)" << endl;
    }

    cout << endl << "After copying baby spinach into dessert:" << endl;
    if (gl.copyEntry("Baby spinach", "Dessert")) {
        gl.display();
    } else {
        cout << "FAILED! (this is correct)" << endl;
    }

    cout << endl << "After copying cheddar into spinach:" << endl;
    if (gl.copyEntry("Cheddar", "Spinach")) {
        gl.display();
    } else {
        cout << "FAILED! (this is correct)" << endl;
    }

    return 0;
}
