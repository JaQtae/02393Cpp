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
unsigned int totalDuration(Song *s, string genre) {
    // current is a pointer to the song s, if its not null, iterate by choosing next as current when done
    for (Song *current = s; current != nullptr; current = current->next) {
        // check if the genre input is valid for current
        if (current->genre == genre){ // Recursively run to next in list and so on...
            return current->duration + totalDuration(current->next, genre);
        }
    }
	return 0; //enables function to work
}


// Task 2(b).  Implement this function
Song *find(Song *s, unsigned int duration) {
    // Dynamically allocated copy means we need to make new Song-object of *s.
    for (Song *current = s; current != nullptr; current = current->next) {
        if (current->duration > duration) { // Longer than specified duration
            Song *newPlaylist = new Song; // Copy everything to newPlaylist
            newPlaylist->artist = current->artist;
            newPlaylist->title = current->title;
            newPlaylist->next = current->next;
            newPlaylist->duration = current->duration;
            newPlaylist->genre = current->genre;
            // Recurse to build up the new playlist by going through elements of s
            newPlaylist->next = find(current->next, duration);
            return newPlaylist;
        }
    }
	return nullptr; // Enables to work incase none are longer.
}


// Task 2(c).  Implement this function
Song* split(Song *&s, unsigned int pos) {
    // Strategy: If we find s = [1 2 3 4], then for pos = 2 we should go until find it
    //           then we know that current->next is the rest of the playlist, so we update
    //           newPlaylist as that, and update s by saying that part is now a nullptr

    // Check if the song exists at position pos
    if (s == nullptr || pos == 0) { return nullptr; }
    if (pos == 1) { // If it splits at start, return entirety as newPlaylist and null out s
        Song* newPlaylist = s;
        s = nullptr;
        return newPlaylist;
    }

    // Internal counter of pos
    unsigned int pos_counter = 1;
    Song* current = s; // Start at head of playlist (s)
    // While current song isn't empty and we haven't reached the queried pos
    while (current != nullptr && pos_counter < pos - 1) {
        current = current->next; // Take next song in playlist
        pos_counter++; // Increment counter
    }
    // We're now at pos
    Song* newPlaylist = current->next; 
    current->next = nullptr; 

	return newPlaylist;
}
