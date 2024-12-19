#include <iostream>
#include <string>
#include "ex02-library.h"
using namespace std;

int main() {
    Passenger p0 = {"Alfred A.", 123, false, nullptr};
    Passenger p1 = {"Barbara B.", 321, true, &p0};
    Passenger p2 = {"Charlie C.", 456, true, &p1};
    Passenger p3 = {"Daria D.", 654, false, &p2};
    Passenger p4 = {"Emil E.", 789, false, &p3};
    Passenger p5 = {"Fiona F.", 987, true, &p4};
    
    Passenger *q = &p5;

    cout << "The passengers queue is: " << endl;
    displayQueue(q);
    cout << endl;

    cout << "The passenger with ticket 456 is: ";
    Passenger *pp = find(q, 456);
    if (pp == nullptr) {
        cout << "nobody!" << endl;
    } else {
        cout << pp->name << endl;
    }

    cout << "The passenger with ticket 987 is: ";
    pp = find(q, 987);
    if (pp == nullptr) {
        cout << "nobody!" << endl;
    } else {
        cout << pp->name << endl;
    }

    cout << "The passenger with ticket 101 is: ";
    pp = find(q, 101);
    if (pp == nullptr) {
        cout << "nobody!" << endl;
    } else {
        cout << pp->name << endl;
    }

    cout << "The passenger with ticket 654 in an empty queue is: ";
    pp = find(nullptr, 654);
    if (pp == nullptr) {
        cout << "nobody!" << endl;
    } else {
        cout << pp->name << endl;
    }

    return 0;
}
