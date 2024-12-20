#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Passenger* find(Passenger *q, unsigned int ticket) {
    // Replace the following with your code

    // Iterate over passengers by pointing *current and going to ->next
    for (Passenger *current = q; current != nullptr; current = current->next) {
            if (current->ticket == ticket) { // Ticket holder found
                return current; // Returns a pointer to Passenger in q
            }
        }
    // Else, did not find ticket holder in queue.
    return nullptr;
}

// Task 2(b).  Implement this function
Passenger* remove(Passenger *q, unsigned int ticket) {
    // Replace the following with your code
    // Can assume at most one passenger has the ticket (unique)
    for (Passenger* current = q; current != nullptr; current = current->next) {
        // For each passenger in q that does NOT have ticket
        if (current->ticket != ticket) { // Add to newQueue
            Passenger* newQueue = new Passenger;
            newQueue->name = current->name; // Update information
            newQueue->priority = current->priority;
            newQueue->ticket = current->ticket;
            // Recursively check if next passenger in q is "target"
            // if it is, then it is skipped and not added to this newQueue
            newQueue->next = remove(current->next, ticket);
            return newQueue;
        }
    }
    return nullptr; // Otherwise, no tickets inside that aren't "target"
}

// Task 2(c).  Implement this function
Passenger* priority(Passenger *q) {
    // Replace the following with your code
    // Return a new queue with priority
    for (Passenger* current = q; current != nullptr; current = current->next) {
        // For each passenger in q that does NOT have ticket
        if (current->priority == true) { // Add to newQueue
            Passenger* priorityQueue = new Passenger;
            priorityQueue->name = current->name; // Update information
            priorityQueue->priority = current->priority;
            priorityQueue->ticket = current->ticket;
            // Recursively check if next passenger in q is "target"
            // if it is, then it is skipped and not added to this newQueue
            priorityQueue->next = priority(current->next);
            return priorityQueue;
        }
    }
    // Otherwise, nobody had priority in q
    return nullptr;
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
