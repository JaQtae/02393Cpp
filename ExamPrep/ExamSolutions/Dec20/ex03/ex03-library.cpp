#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
SongDatabase::SongDatabase() {
    this->songs.push_back("Penny Lane");
    this->songsInfo["Penny Lane"] = {"https://youtu.be/S-rB0pHI9fU", 8};

    this->songs.push_back("Trololo");
    this->songsInfo["Trololo"] = {"https://youtu.be/oavMtUWDBTM", 10};

    this->songs.push_back("Ob-La-Di, Ob-La-Da");
    this->songsInfo["Ob-La-Di, Ob-La-Da"] = {"https://youtu.be/_J9NpHKrKMw", 2};

    this->songs.push_back("Don't Worry, Be Happy");
    this->songsInfo["Don't Worry, Be Happy"] = {"https://youtu.be/d-diB65scQU", 3};

    this->songs.push_back("Leave My Kitten Alone");
    this->songsInfo["Leave My Kitten Alone"] = {"https://youtu.be/7BKsy9-Bvok", 5};
}

// Task 3(a).  Implement this method
void SongDatabase::display() {
    // Write your code here
    for (auto it = this->songs.begin(); it != this->songs.end(); it++) {
        Info &info = this->songsInfo[*it];
        cout << "title=" << *it << "; ";
        cout << "url=" << info.url << "; ";
        cout << "score=" << info.score << endl;
    }
}

// Task 3(b).  Implement this method
bool SongDatabase::addSong(string title, string url, unsigned int score) {
    // Write your code here
    if (score > 10) {
        return false;
    }
    for (auto it = this->songs.begin(); it != songs.end(); it++) {
        if (*it == title) {
            return false;
        }
    }
    this->songs.push_back(title);
    this->songsInfo[title] = {url, score};
    return true;
}

// Task 3(a).  Implement this method
void SongDatabase::searchSongs(string howGood) {
    // Write your code here
    for (auto it = this->songs.begin(); it != this->songs.end(); it++) {
        Info &info = this->songsInfo[*it];
        if (((howGood == "abysmal") && (info.score < 3)) ||
            ((howGood == "lousy") && (info.score >= 3) && (info.score < 5)) ||
            ((howGood == "meh") && (info.score >= 5) && (info.score < 7)) ||
            ((howGood == "cool") && (info.score >= 7) && (info.score < 9)) ||
            ((howGood == "OMG") && (info.score >= 9))) {
                cout << "title=" << *it << "; ";
                cout << "url=" << info.url << "; ";
                cout << "score=" << info.score << endl;
        }
    }
}
