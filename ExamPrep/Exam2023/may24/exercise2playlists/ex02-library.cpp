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
    // For each song in the playlist (if it isn't empty)
    // current song s, not empty(nullptr), and for next song (current->next)
    for (Song *current = s; current != nullptr; current = current->next) {
        // if current song genre == genre input, add duration to a running total
        if (current->genre == genre) {
            // return curent song duration + recursive call of function
            // ie. next song, next song, next song, etc. until nullptr
            return current->duration + totalDuration(current->next, genre);
        }
    }
    return 0; // To make function work :)

}


// Task 2(b).  Implement this function
Song *find(Song *s, unsigned int duration) {
    // return Songs in playlist s longer than specified duration
    // preserve ordering of songs in playlist
    // dynamically allocated copy of original s, and not modify s

    // For each song in the playlist (if it isn't empty)  
    for (Song *current = s; current != nullptr; current = current->next) {
        // If it's longer than specified duration
        if (current->duration > duration) {
            // Create new Song (playlist) and copy current song info to it
            Song* newPlaylist = new Song;
            newPlaylist->title = current->title;
            newPlaylist->artist = current->artist;
            newPlaylist->genre = current->genre;
            newPlaylist->duration = current->duration;
            // Recursively call function for next song in playlist
            // ie. if it finds next song in current to fulfill condition
            // add it as next to newPlaylist
            newPlaylist->next = find(current->next, duration);
            return newPlaylist;
        }
    }

	return nullptr;
}


// Task 2(c).  Implement this function
Song* split(Song *&s, unsigned int pos) {


    // Check if song exists at position pos:
        // if NOT, empty newPlaylist without altering original s
        // if YES, update s by removing all songs at position pos and onwards
        // and add them to newPlaylist, in same order

    // If playlist is empty, or position is 0, return nullptr
    if (s == nullptr || pos == 0) {
        return nullptr;
    }
    // If it splits at first song, return the entirety of the playlist s

    if (pos == 1) {
        Song* newPlaylist = s;
        s = nullptr;
        return newPlaylist;
    }

    // Keep a count of position
    unsigned int pos_counter = 1;
    Song* current = s; // Start at head of playlist (s)

    // While valid song and not reached position pos yet
    while (current != nullptr && pos_counter < pos - 1) {
        current = current->next; // Take next song in playlist
        pos_counter++; // Increment counter
    }

    // New playlist recursively pointing at next song(s)
    Song* newPlaylist = current->next; 
    current->next = nullptr; // Cut off original playlist at position pos

    return newPlaylist;
    
}
