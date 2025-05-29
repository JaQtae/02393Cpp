#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    ParkingArea area = ParkingArea();

    cout << "Initial parking spaces occupancy:" << endl;
    area.display();

    vector<string> v;
    v.push_back("AB123XY");
    area.leave(v);
    cout << endl << "After the vehicle with license plate AB123XY has left the parking space:" << endl;
    area.display();

    v.clear();
    v.push_back("EF456SA");
    area.leave(v);
    cout << endl << "After the vehicle with license plate EF456SA has left the parking space:" << endl;
    area.display();

    v.clear();
    v.push_back("EF456SA");
    area.leave(v);
    cout << endl << "After trying to notify again that the vehicle with license plate EF456SA has left the parking space:" << endl;
    area.display();

    v.clear();
    v.push_back("GH102MN");
    v.push_back("IJ102LK");
    area.leave(v);
    cout << endl << "After trying to notify that the vehicles with license plate IJ102LK - which is NOT parked - and GH102MN - which is parked - have left the parking space:" << endl;
    area.display();

    v.clear();
    v.push_back("AX132MA");
    v.push_back("IZ501LL");
    cout << endl << "After trying to notify that the vehicles with license plate AX132MA and IZ501LL - which are both NOT parked - have left the parking space:" << endl;
    area.display();

    return 0;
}
