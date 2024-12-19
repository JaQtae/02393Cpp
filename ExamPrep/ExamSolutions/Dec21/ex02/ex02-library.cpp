#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Passenger* find(Passenger *q, unsigned int ticket) {
    if (q == nullptr) {
        return nullptr; // We reached the end of the list
    } else if (q->ticket == ticket) {
        return q;
    } else {
        return find(q->next, ticket);
    }
}

// Task 2(b).  Implement this function
Passenger* remove(Passenger *q, unsigned int ticket) {
    if (q == nullptr) {
        return nullptr; // We reached the end of the list
    } else if (q->ticket == ticket) {
        // We skip the passenger; the rest of the queue remains the same
        return q->next;
    } else {
        // We create a new list, copying the contents of q
        Passenger *p = new Passenger;
        p->name = q->name;
        p->ticket = q->ticket;
        p->priority = q->priority;
        p->next = remove(q->next, ticket);
        return p;
    }
}

// Task 2(c).  Implement this function
Passenger* priority(Passenger *q) {
    if (q == nullptr) {
        return nullptr; // We reached the end of the list
    } else if (!q->priority) {
        // We skip the passenger
        return priority(q->next);
    } else {
        // We create a new list, copying the contents of q
        Passenger *p = new Passenger;
        p->name = q->name;
        p->ticket = q->ticket;
        p->priority = q->priority;
        p->next = priority(q->next);
        return p;
    }
}

// Do not modify
void displayQueue(Passenger *q) {
    if (q == nullptr) {
        return;
    }
    cout << q->name << " - ticket: " << q->ticket;
    if (q->priority) {
        cout << " (priority)";
    }
    cout << endl;
    displayQueue(q->next);
}
