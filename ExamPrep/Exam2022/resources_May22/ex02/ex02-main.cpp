#include <iostream>
#include <string>
#include "ex02-library.h"
using namespace std;

int main() {
    Passenger p0 = {"Alfred A.", 123, 5, 'A', nullptr};
    Passenger p1 = {"Barbara B.", 321, 1, 'B', &p0};
    Passenger p2 = {"Charlie C.", 456, 10, 'D', &p1};
    Passenger p3 = {"Daria D.", 654, 22, 'C', &p2};
    Passenger p4 = {"Emil E.", 789, 10, 'E', &p3};
    Passenger p5 = {"Fiona F.", 987, 21, 'F', &p4};
    
    Passenger *q = &p5;

    cout << "The passengers queue is: " << endl;
    displayQueue(q);
    cout << endl;

    shift(q, 2);
    cout << "After shifting the passengers by 2 rows we have: " << endl;
    displayQueue(q);
    cout << endl;

    cout << "The passengers sitting between rows 5 and 12 are: " << endl;
    Passenger *q2 = find(q, 5, 12);
    if (q2 == nullptr) { cout << "nobody!" << endl; }
    else { displayQueue(q2); }
    cout << endl;

    cout << "Is seat 10D occupied? ";
    if (occupied(q, 10, 'D')) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Is seat 12E occupied? ";
    if (occupied(q, 12, 'E')) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    return 0;
}
