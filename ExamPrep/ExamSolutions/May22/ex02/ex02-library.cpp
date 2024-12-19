#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
void shift(Passenger *q, unsigned int n) {
    if (q == nullptr) {
        return; // We reached the end of the list
    } else {
        q->row += n;
        shift(q->next, n);
    }
}

// Task 2(b).  Implement this function
Passenger* find(Passenger *q, unsigned int rowMin, unsigned int rowMax) {
    if (q == nullptr) {
        return nullptr; // We reached the end of the list
    } else if ((q->row  >= rowMin) && (q->row <= rowMax)) {
        // The passenger is within the row range, so we copy it
        Passenger *p = new Passenger;
        p->name = q->name;
        p->ticket = q->ticket;
        p->row = q->row;
        p->seat = q->seat;
        p->next = find(q->next, rowMin, rowMax);
        return p;
    } else {
        // The passenger is outside the row range, so we skip it
        return find(q->next, rowMin, rowMax);
    }
}

// Task 2(c).  Implement this function
bool occupied(Passenger *q, unsigned int row, char seat) {
    if (q == nullptr) {
        return false; // We reached the end of the list
    } else if ((q->row == row) && (q->seat == seat)) {
        // We found a passenger sitting in the given seat
        return true;
    } else {
        // We continue the search
        return occupied(q->next, row, seat);
    }
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
