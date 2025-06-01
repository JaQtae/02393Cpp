#include <iostream>
#include <string>
#include "ex02-library.h"
using namespace std;

int main() {
    Song s0 = {"Barbie Girl", "Aqua", "Dance", 196, nullptr};
    Song s1 = {"Never Gonna Give You Up", "Rick Hashley", "Pop", 215, &s0};
    Song s2 = {"Sandstorm", "Darude", "Dance", 225, &s1};
    Song s3 = {"Billie Jean", "Micheal Jackson", "Pop", 232, &s2};
    
    Song *s = &s3;

    cout << "The playlist is: " << endl;
    displayPlaylist(s);
    cout << endl;

    cout << "The total duration of the playlist is: ";
    cout << totalDuration(s) << " seconds" << endl;
    cout << endl;

    Song *ps = find(s, "Pop");
    cout << "A new playlist containing only pop songs is: " << endl;
    displayPlaylist(ps);
    cout << endl;


    Song *ds = find(s, "Dance");
    cout << "A new playlist containing only dance songs is: " << endl;
    displayPlaylist(ds);
    cout << endl;
    
    shift(s, 2, 2);
    cout << "After shifting the second song after 2 songs, the original playlist is:" << endl;
    displayPlaylist(s);
    cout << endl;

    shift(ds, 1, 1);
    cout << "After shifting the first song after 1 song, the dance playlist is:" << endl;
    displayPlaylist(ds);
    cout << endl;


    return 0;
}
