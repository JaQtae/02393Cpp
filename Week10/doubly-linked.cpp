#include "doubly-linked.h"

// Constructor: Initialize a new, empty DL-list
List::List(void) : first(nullptr) {} // nullptr -> 0

// Destructor
List::~List(void) {
    Node* current = first;
    while (current != nullptr) { // traverse list and delete each node
        Node* nextNode = current->next; // pointer to the next node
        delete current;
        current = nextNode;
    }
}

// Insert an integer at the end of the list
void List::insert(int n) {
    Node* newNode = new Node{n, nullptr, nullptr}; // n_new(val=n, next=null, prev=null)
    if (first == nullptr) { // If the list is empty
        first = newNode;
    } else {
        Node* current = first;
        while (current->next != nullptr) { // traverse entire list
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Reverse the list
void List::reverse(void) {
    Node* current = first;
    Node* prevNode = nullptr;
    
    while (current != nullptr) {
        // Swap next and prev pointers
        Node* nextNode = current->next;
        current->next = prevNode;
        current->prev = nextNode;
        
        // Move prevNode and current pointers forward
        prevNode = current;
        current = nextNode;
    }
    // Update the head of the list
    first = prevNode;
}

// Print the list
void List::print(void) {
    Node* current = first;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << " ";
        }
        current = current->next;
    }
    cout << endl;
}
