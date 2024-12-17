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

unsigned int totalDuration(Song *s, string genre);
Song* find(Song *s, unsigned int duration);
Song* split(Song *&s, unsigned int pos);

#endif /* EX02_LIBRARY_H_ */
