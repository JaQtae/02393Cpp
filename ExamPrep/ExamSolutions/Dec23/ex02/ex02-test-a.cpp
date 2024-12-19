#include <iostream>
#include <string>
#include "ex02-library.h"
using namespace std;

int main() {
    cout << "Creating a first playlist" << endl << endl;

    Song s0 = {"Song1", "ArtistA", "Rock", 230, nullptr};
    Song s1 = {"Song2", "ArtistB", "Pop", 195, &s0};
    Song s2 = {"Song3", "ArtistA", "Dance", 302, &s1};
    Song s3 = {"Song4", "ArtistC", "Rap", 232, &s2};
    
    Song *s = &s3;

    cout << "The first playlist is: " << endl;
    displayPlaylist(s);
    cout << endl;

    cout << "The total duration of the first playlist is: ";
    cout << totalDuration(s) << " seconds" << endl;
    cout << endl;

    cout << "Creating a second playlist" << endl << endl;

    Song ss0 = {"Song5", "ArtistA", "Pop", 185, nullptr};
    Song ss1 = {"Song6", "ArtistC", "Pop", 223, &ss0};
    Song ss2 = {"Song7", "ArtistC", "Dance", 256, &ss1};
    Song ss3 = {"Song8", "ArtistD", "Rock", 248, &ss2};
    Song ss4 = {"Song9", "ArtistE", "Rap", 312, &ss3};
    Song ss5 = {"Song10", "ArtistB", "Rock", 298, &ss4};
    
    Song *ss = &ss5;

    cout << "The second playlist is: " << endl;
    displayPlaylist(ss);
    cout << endl;

    cout << "The total duration of the playlist is: ";
    cout << totalDuration(ss) << " seconds" << endl;
    cout << endl;

    cout << "Creating a third playlist" << endl << endl;

    Song sb0 = {"Song11", "ArtistA", "Pop", 203, nullptr};

    Song *sb = &sb0;

    cout << "The third playlist is: " << endl;
    displayPlaylist(sb);
    cout << endl;

    cout << "The total duration of the playlist is: ";
    cout << totalDuration(sb) << " seconds" << endl;
    cout << endl;

    
    return 0;
}
