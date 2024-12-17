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
{
    return 0;
}

// Task 2(b).  Implement this function
Song *find(Song *s, string genre)
{
    return nullptr;
}

// Task 2(c).  Implement this function
bool shift(Song *&s, unsigned int pos, unsigned int n)
{
    return true;
}
