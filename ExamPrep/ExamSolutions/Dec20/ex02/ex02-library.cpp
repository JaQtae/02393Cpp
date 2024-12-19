#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
unsigned int length(Elem *list) {
    // Write your code here
    if (list == nullptr) {
        return 0;
    } else {
        return list->times + length(list->next);
    }
}

// Task 2(b).  Implement this function
Elem* append(Elem *list, int v) {
    // Write your code here
    if (list == nullptr) {
        Elem *e = new Elem;
        e->value = v;
        e->times = 1;
        e->next = nullptr;
        return e;
    }

    // The given list is not empty: find the last element
    Elem *last = list;
    while (last->next != nullptr) {
        last = last->next;
    }

    if (last->value == v) {
        // The last element of the list already contains v
        last->times = last->times + 1;
    } else {
        // The last element of the list does not contains v:
        // let's create a new element.
        Elem *e = new Elem;
        e->value = v;
        e->times = 1;
        e->next = nullptr;
        last->next = e;
    }
    return list;
}

// Task 2(c).  Implement this function
Elem* buildRLEList(int *data, unsigned int n) {
    // Write your code here
    Elem *result = nullptr; // RLE list that will be returned

    for (unsigned int i = 0; i < n; i++) {
        result = append(result, data[i]);
    }
    return result;
}


// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
