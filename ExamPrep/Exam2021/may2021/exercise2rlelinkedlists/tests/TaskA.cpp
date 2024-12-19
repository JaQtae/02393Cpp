#include <iostream>
#include <string>
#include "ex02-library.h"

using namespace std;

int main() {
    Elem e0 = {10, 5, nullptr};
    Elem e1 = {12, 6, &e0};
    Elem e2 = {4, 10, &e1};

    cout << "Reverse of an empty RLE list: ";
    displayRLEList(reverse(nullptr));

    cout << endl << "Reverse of RLE list starting with e0:";
    displayRLEList(reverse(&e0));

    cout << endl << "Reverse of RLE list starting with e2:";
    displayRLEList(reverse(&e2));
    cout << endl;

    return 0;
}
