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

    Song *ps = find(ss, "Pop");
    cout << "A new playlist containing only pop songs is : ";
    displayPlaylist(ps);
    cout << endl;

    Song *ds = find(ss, "Dance");
    cout << "A new playlist containing only dance songs is : ";
    displayPlaylist(ds);
    cout << endl;

    Song *cs = find(ss, "Country");
    cout << "A new playlist containing only country songs is : ";
    displayPlaylist(cs);
    cout << endl;

    return 0;
}
