#ifndef EX02_LIBRARY_H_
#define EX02_LIBRARY_H_

#include <string>

struct Passenger {
    std::string name;
    unsigned int ticket;
    bool priority;
    Passenger *next;
};

void displayQueue(Passenger *q);

Passenger* find(Passenger *q, unsigned int ticket);
Passenger* remove(Passenger *q, unsigned int ticket);
Passenger* priority(Passenger *q);

#endif /* EX02_LIBRARY_H_ */
