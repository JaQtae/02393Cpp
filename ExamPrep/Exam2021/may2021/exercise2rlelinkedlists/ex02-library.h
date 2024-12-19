#ifndef EX02_LIBRARY_H_
#define EX02_LIBRARY_H_

struct Elem {
    int value;
    unsigned int times; // Number of repetitions
    Elem *next;
};

void displayRLEList(Elem *list);

Elem* reverse(Elem *list);
Elem* concatenate(Elem *list1, Elem *list2);
int sum(Elem *list);

#endif /* EX02_LIBRARY_H_ */
