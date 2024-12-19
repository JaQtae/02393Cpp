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
unsigned int totalDuration(Song *s, string genre)
{
    if (s == nullptr) {
        return 0;
    } else {
        if(s->genre == genre)
            return s->duration + totalDuration(s->next, genre);
        else
            return totalDuration(s->next, genre);
    }
}

void buildR(Song *currSong, Song *&head, Song *&tail, unsigned int duration){
    if(currSong == nullptr) {
        return;
    } else {
        if(currSong->duration > duration) {
            Song *copiedSong = new Song {currSong->title, currSong->artist, currSong->genre, currSong->duration, nullptr};
            if(head == nullptr) {
                //add first element
                head = copiedSong;
                tail = copiedSong;
            } else {
                //push back element
                tail->next = copiedSong;
                tail = tail->next;
            }
        }
        buildR(currSong->next, head, tail, duration);
    }
}

// Task 2(b).  Implement this function
Song *find(Song *s, unsigned int duration)
{
    Song *head = nullptr;
    Song *tail = nullptr;
    buildR(s, head, tail, duration);
    return head;
}

Song *&findR(Song *&currSong, unsigned int i, unsigned int n) {
    if(i == n){
        return currSong;
    } else {
        return findR(currSong->next, i+1, n);
    }
}

// Task 2(c).  Implement this function
Song* split(Song *&s, unsigned int pos)
{
    unsigned int count = 0;
    for (Song *s2 = s; s2 != nullptr; s2 = s2->next){
        count++;    
    }
    
    if(pos < 1 || pos > count){
        return nullptr;
    }

    // find song at specified position
    Song *&song = findR(s, 0, pos-1);
    Song *temp = song;
    song = nullptr;
    return temp;

}
