#include <iostream>
#include <vector>
#include <cmath>
#include "shapes.h"

using namespace std;

int main(void){

    Rectangle u(2,3);
    Square v(2);
    Circle w(1);

    // Print all areas
    cout << "Areas..." << endl;
    cout << round(u.area()) << endl;
    cout << round(v.area()) << endl;
    cout << round(w.area()) << endl;

    // Print all perimeters
    cout << "Perimeters..." << endl;
    cout << round(u.perimeter()) << endl;
    cout << round(v.perimeter()) << endl;
    cout << round(w.perimeter()) << endl;

    return 0;

}
