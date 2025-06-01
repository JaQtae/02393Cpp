#ifndef EX02_LIBRARY_H_
#define EX02_LIBRARY_H_

#include <string>

using namespace std;

struct Song {
    string title;
    string artist;
    string genre;
    unsigned int duration;
    Song *next;
};

void displayPlaylist(Song *s);

unsigned int totalDuration(Song *s);
Song* find(Song *s, string genre);
bool shift(Song *&s, unsigned int pos, unsigned int n);

#endif /* EX02_LIBRARY_H_ */
