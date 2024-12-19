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
    if (s == nullptr) {
        return 0;
    } else {
        return s->duration + totalDuration(s->next);
    }
}

void buildR(Song *currSong, Song *&head, Song *&tail, string genre){
    if(currSong == nullptr) {
        return;
    } else {
        if(currSong->genre == genre) {
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
        buildR(currSong->next, head, tail, genre);
    }
}

// Task 2(b).  Implement this function
Song *find(Song *s, string genre)
{
    Song *head = nullptr;
    Song *tail = nullptr;
    buildR(s, head, tail, genre);
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
bool shift(Song *&s, unsigned int pos, unsigned int n)
{
    int count = 0;
    for (Song *s2 = s; s2 != nullptr; s2 = s2->next){
        count++;    
    }
    
    if(pos < 1 || pos+n > count){
        return false;
    }

    Song *&first = findR(s, 0, pos-1);
    Song *last = findR(s, 0, pos-1+n);
    
    //remove item from pos
    Song *temp = first;
    first = first->next;

    //insert item after pos+n
    temp->next = last->next;
    last->next = temp;
    
    return true;

}
