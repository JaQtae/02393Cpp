#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Elem* reverse(Elem *list) {
    // Write your code here
    Elem *prev = nullptr;
    Elem *curr = list;
    Elem *next = nullptr;

    while (curr != nullptr) {
        // Remember the next element to process
        next = curr->next;

        // Make the current element point back to the previous
        curr->next = prev;
        
        // Move the pointers one element ahead
        prev = curr;
        curr = next;
    }

    // prev now contains the first element of the reversed list
    return prev;
}

// Task 2(b).  Implement this function
Elem* concatenate(Elem *list1, Elem *list2) {
    // Write your code here
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }

    // Find the last element of list 1
    Elem *last = list1;
    while (last->next != nullptr) {
        last = last->next;
    }

    if (last->value == list2->value) {
        // We merge the last element of list1 and the first element of list2
        last->times += list2->times;
        last->next = list2->next;
    } else {
        // We just attach list2 at the end of list1
        last->next = list2;
    }
    return list1;
}

// Task 2(c).  Implement this function
int sum(Elem *list) {
    // Write your code here
    int total = 0;
    while (list != nullptr) {
        total += list->value * list->times;
        list = list->next;
    }
    return total;
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
