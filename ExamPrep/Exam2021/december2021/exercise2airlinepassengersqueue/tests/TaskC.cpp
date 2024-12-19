#include <iostream>
#include <string>
#include "ex02-library.h"
using namespace std;

int main() {
    Passenger p0 = {"Alfred A.", 123, false, nullptr};
    Passenger p1 = {"Barbara B.", 321, true, &p0};
    Passenger p2 = {"Charlie C.", 456, true, &p1};
    Passenger p3 = {"Daria D.", 654, false, &p2};
    Passenger p4 = {"Emil E.", 789, true, &p3};
    Passenger p5 = {"Fiona F.", 987, false, &p4};
    
    Passenger *q = &p5;

    cout << "The passengers queue is: " << endl;
    displayQueue(q);
    cout << endl;

    Passenger *qp = priority(q);
    cout << "The queue of priority passengers is:" << endl;
    displayQueue(qp);
    cout << endl;

    Passenger *qp2 = priority(nullptr);
    cout << "The queue of priority passengers in an empty queue is:" << endl;
    displayQueue(qp2);

    return 0;
}
