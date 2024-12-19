#include <iostream>
#include "ex02-library.h"
using namespace std;

int main() {
    Elem e0 = {10, 5, nullptr};
    Elem e1 = {12, 6, &e0};
    Elem e2 = {4, 10, &e1};

    Elem e4 = {100, 7, nullptr};
    Elem e5 = {4,   3, &e4};
    Elem e6 = {101, 9, &e5};
    
    cout << "The RLE list is: " << endl;
    displayRLEList(&e2);
    cout << endl;

    cout << "The reversed list is:" << endl;
    Elem *r = reverse(&e2);
    displayRLEList(r);

    cout << endl;

    cout << "After concatenation, the list is:" << endl;
    Elem *l = concatenate(r, &e6);
    displayRLEList(l);
    cout << endl;

    cout << "The sum of its elements is: " << sum(l) << endl;
    
    return 0;
}
