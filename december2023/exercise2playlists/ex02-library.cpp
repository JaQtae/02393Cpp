#include <iostream>
#include "ex02-library.h"
using namespace std;



// Do not modify
void displayPlaylist(Song *s) {
    if (s == nullptr) {
        return;
    }
    cout << s->title << ", ";
    cout << s->artist << ", ";
    cout << s->genre << ", ";
    cout << s->duration << ", " << endl;
    
    displayPlaylist(s->next);
}

// Task 2(a).  Implement this function
unsigned int totalDuration(Song *s)
{   // Recursive
    if (s == nullptr) {
        return 0;
    } else {
        return s->duration + totalDuration(s->next);
    }
    // Iterative
    unsigned int total = 0;
    while (s != nullptr) {
        total += s->duration;
        s = s->next;
    }
    return total;
}

// Task 2(b).  Implement this function
Song *find(Song *s, string genre)
{
    for (Song *current = s; current != nullptr; current = current->next) {
        if (current->genre == genre) {
            Song *newPlaylist = new Song; // Copy everything to newPlaylist
            newPlaylist->artist = current->artist;
            newPlaylist->title = current->title;
            newPlaylist->next = current->next;
            newPlaylist->duration = current->duration;
            newPlaylist->genre = current->genre;
            newPlaylist->next = find(current->next, genre);
            return newPlaylist;
        }
    }

    return nullptr;
}

// Task 2(c).  Implement this function
bool shift(Song *&s, unsigned int pos, unsigned int n) {
    // Step 1: Count the total number of songs
    unsigned int count = 0;
    for (Song *curr = s; curr != nullptr; curr = curr->next) {
        count++;
    }

    // Step 2: Validate input
    if (pos < 1 || pos + n > count) {
        return false;
    }

    // Step 3: Find the pointer to the (pos-1)th node (prev)
    Song **prev = &s;  // pointer to pointer to node at index (pos-1)
    for (unsigned int i = 1; i < pos; ++i) {
        prev = &((*prev)->next);
    }

    // Step 4: Detach node at position `pos`
    Song *target = *prev;         // node at pos
    *prev = target->next;         // remove from current position

    // Step 5: Find the (pos + n - 1)th node (insertion point)
    Song *insertion = *prev;      // start from pos (which is now the node after removal)
    for (unsigned int i = 1; i < n; ++i) {
        insertion = insertion->next;
    }

    // Step 6: Insert target after insertion
    target->next = insertion->next;
    insertion->next = target;

    return true;
}

