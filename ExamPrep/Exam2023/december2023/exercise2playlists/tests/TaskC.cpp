#include <iostream>
#include <string>
#include "ex02-library.h"
using namespace std;

int main() {
    cout << "Creating a playlist" << endl << endl;

    Song ss0 = {"Song1", "ArtistA", "Pop", 185, nullptr};
    Song ss1 = {"Song2", "ArtistB", "Pop", 223, &ss0};
    Song ss2 = {"Song3", "ArtistB", "Dance", 256, &ss1};
    Song ss3 = {"Song4", "ArtistC", "Rock", 248, &ss2};
    Song ss4 = {"Song5", "ArtistD", "Rap", 312, &ss3};
    Song ss5 = {"Song6", "ArtistD", "Rock", 298, &ss4};
    
    Song *ss = &ss5;

    cout << "The playlist is: " << endl;
    displayPlaylist(ss);
    cout << endl;

    cout << "Shifting songs to sort the playlist by genre: " << endl;
    shift(ss, 5, 1);
    shift(ss, 3, 3);
    shift(ss, 1, 5);
    shift(ss, 1, 3);

    cout << "The playlist is now: " << endl;
    displayPlaylist(ss);
    cout << endl;

    cout << "Trying to move songs to a non-existent position: " << endl;
    bool result = false;
    result |= shift(ss, 1, 6);
    result |= shift(ss, 4, 3);
    result |= shift(ss, 6, 1);
    
    if(result) {
        cout << "wrong return value when invoking placeShip" << endl;
    }

    cout << "Trying to move songs from a non-existent position: " << endl;
    result = false;
    result |= shift(ss, 0, 2);
    result |= shift(ss, 7, 1);
    
    if(result) {
        cout << "wrong return value when invoking placeShip" << endl;
    }

    cout << "The playlist is now: " << endl;
    displayPlaylist(ss);
    cout << endl;

    return 0;
}
