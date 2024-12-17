#ifndef EX02_LIBRARY_H_
#define EX02_LIBRARY_H_

#include <string>

struct Passenger {
    std::string name;
    unsigned int ticket;
    unsigned int row;
    char seat;
    Passenger *next;
};

void displayQueue(Passenger *q);

void shift(Passenger *q, unsigned int n);
Passenger* find(Passenger *q, unsigned int rowMin,
                unsigned int rowMax);
bool occupied(Passenger *q, unsigned int row, char seat);

#endif /* EX02_LIBRARY_H_ */
