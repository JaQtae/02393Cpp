#include <iostream>
#include <string>
#include "ex02-library.h"

using namespace std;

int main() {
    Elem e0 = {3, 5, nullptr};
    Elem e1 = {2, 6, &e0};
    Elem e2 = {1, 9, &e1};

    Elem e4 = {6, 7, nullptr};
    Elem e5 = {5, 3, &e4};
    Elem e6 = {4, 2, &e5};

    Elem e7 = {8, 5, nullptr};
    Elem e8 = {7, 5, &e7};
    Elem e9 = {6, 3, &e8};

    cout << "Initial list:" << endl;
    displayRLEList(&e2);
    cout << endl;

    cout << "Result of concatenation with an empty list (1):" << endl;
    Elem *c0 = concatenate(nullptr, &e2);
    displayRLEList(c0);
    cout << endl;

    cout << "Result of concatenation with an empty list (2):" << endl;
    Elem *c1 = concatenate(c0, nullptr);
    displayRLEList(c1);
    cout << endl;

    cout << "Result of concatenation with e6:" << endl;
    Elem *c2 = concatenate(c1, &e6);
    displayRLEList(c2);
    cout << endl;

    cout << "Result of concatenation with e9:" << endl;
    Elem *c3 = concatenate(c2, &e9);
    displayRLEList(c3);
    cout << endl;

    return 0;
}
