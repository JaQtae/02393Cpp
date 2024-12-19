#include <iostream>
#include <string>
#include "ex02-library.h"

using namespace std;

int main() {
    Elem e0 = {10, 5, nullptr};
    Elem e1 = {12, 6, &e0};
    Elem e2 = {4, 10, &e1};

    cout << "The sum of the elements of an empty list is: " << sum(nullptr);
    cout << endl;

    cout << "The sum of the elements of e0 is: " << sum(&e0) << endl;

    cout << "The sum of the elements of e1 is: " << sum(&e1) << endl;

    cout << "The sum of the elements of e2 is: " << sum(&e2) << endl;

    return 0;
}
