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

    cout << "The total duration of dance songs in the playlist is: ";
    cout << totalDuration(s, "Dance") << " seconds" << endl;
    cout << endl;

    Song *ps = find(s, 220);
    cout << "A new playlist containing only songs longer than 220 seconds is: " << endl;
    displayPlaylist(ps);
    cout << endl;


    Song *ds = find(s, 200);
    cout << "A new playlist containing only songs longer than 200 seconds is: " << endl;
    displayPlaylist(ds);
    cout << endl;
    
    Song *ss = split(s, 3);
    cout << "After splitting the playlist from the third song onwards, the original playlist is:" << endl;
    displayPlaylist(s);
    cout << endl;
    cout << "After splitting the playlist from the third song onwards, the new playlist is:" << endl;
    displayPlaylist(ss);
    cout << endl;

    
    return 0;
}
