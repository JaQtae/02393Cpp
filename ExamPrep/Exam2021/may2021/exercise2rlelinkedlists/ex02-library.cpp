#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Elem* reverse(Elem *list) {
    // Write your code here
    // Init head of linked list
    Elem* head = list;
    // Empty or one element
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    // (1)->(2)->(3)->(4)->(5)->()
    // => (head)->(rest) [Rest is 2<-3<-4<-5]
    // Recursively go through each node and reverse the pointer
    Elem* rest = reverse(head->next);
    // => (head)->()
    // Remove link between (head) and (rest)
    head->next->next = head;
    // head is the new end of the list
    head->next = NULL;
    // Return rest
    return rest;

}

// Task 2(b).  Implement this function
Elem* concatenate(Elem *list1, Elem *list2) {
    // Write your code here

    // If list1 is empty, return list2
    if (list1 == nullptr) {
        return list2;
    }
    // If list2 is empty, return list1
    if (list2 == nullptr) {
        return list1;
    }

    // Traverse to the end of list1
    Elem* last = list1;
    while (last->next != nullptr) {
        last = last->next;
    }
    // If last elem in list1 is same as list2
    if (last->value == list2->value) {
        last->times += list2->times; // merge TIMES of elements
        last->next = list2->next; // point to next element
    } else {
        last->next = list2; // attach list2 to end of list1
    }
    return list1;
}

// Task 2(c).  Implement this function
int sum(Elem *list) {
    // Write your code here
    for (auto i = list; i != nullptr; i = i->next) {
        // If list is empty, return 0
        if (list == nullptr) {
            return 0;
        }
        // Sum X times of value + sum X times of next element, etc.
        return i->value * i->times + sum(i->next);
    }
	return 0;
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
