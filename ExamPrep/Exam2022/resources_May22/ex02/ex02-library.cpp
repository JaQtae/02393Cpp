#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
void shift(Passenger *q, unsigned int n) {
    // Write your code here
}

// Task 2(b).  Implement this function
Passenger* find(Passenger *q, unsigned int rowMin,
                unsigned int rowMax) {
    // Replace the following with your code
    return nullptr;
}

// Task 2(c).  Implement this function
bool occupied(Passenger *q, unsigned int row, char seat) {
    // Replace the following with your code
    return false;
}

// Do not modify
void displayQueue(Passenger *q) {
    if (q == nullptr) {
        return;
    }
    cout << q->name << " - ticket: " << q->ticket;
    cout << ", seat " << q->row << q->seat << endl;
    displayQueue(q->next);
}
