#include <iostream>
#include <string>
#include "ex02-library.h"
using namespace std;

int main() {
    cout << "Creating a playlist" << endl << endl;

    Song s0 = {"Song1", "ArtistA", "Pop", 185, nullptr};
    Song s1 = {"Song2", "ArtistB", "Pop", 223, &s0};
    Song s2 = {"Song3", "ArtistB", "Dance", 256, &s1};
    Song s3 = {"Song4", "ArtistC", "Rock", 248, &s2};
    Song s4 = {"Song5", "ArtistD", "Rap", 312, &s3};
    Song s5 = {"Song6", "ArtistD", "Rock", 298, &s4};
    
    Song *s = &s5;

    cout << "The playlist is: " << endl;
    displayPlaylist(s);
    cout << endl;

    cout << "Splitting the playlist from the fourth song: " << endl;
    Song* ns = split(s, 4);
    
    cout << "The playlist is now: " << endl;
    displayPlaylist(s);
    cout << endl;
    cout << "The new playlist is:" << endl;
    displayPlaylist(ns);
    cout << endl;

    cout << "Splitting the new playlist from the second song: " << endl;
    Song* ns2 = split(ns, 2);
    
    cout << "The playlist is now: " << endl;
    displayPlaylist(ns);
    cout << endl;
    cout << "The new playlist is:" << endl;
    displayPlaylist(ns2);
    cout << endl;




    cout << "Creating a second playlist" << endl << endl;

    Song ss0 = {"Song5", "ArtistA", "Pop", 185, nullptr};
    Song ss1 = {"Song6", "ArtistC", "Pop", 223, &ss0};
    Song ss2 = {"Song7", "ArtistC", "Dance", 256, &ss1};
    Song ss3 = {"Song8", "ArtistD", "Rock", 248, &ss2};
    Song ss4 = {"Song9", "ArtistE", "Rap", 312, &ss3};
    Song ss5 = {"Song10", "ArtistB", "Rock", 298, &ss4};
    
    Song *ss = &ss5;

    cout << "Trying to split the second playlist from the (non-existent) seventh song: " << endl;
    Song* nss = split(ss, 7);
    
    cout << "The playlist is now: " << endl;
    displayPlaylist(ss);
    cout << endl;
    cout << "The new playlist is:" << endl;
    displayPlaylist(nss);
    cout << endl;

    cout << "Creating a third playlist" << endl << endl;

    Song sss0 = {"Song11", "ArtistE", "Dance", 234, nullptr};
    Song sss1 = {"Song12", "ArtistF", "Dance", 233, &sss0};
    Song sss2 = {"Song13", "ArtistC", "Rock", 242, &sss1};
    Song sss3 = {"Song14", "ArtistD", "Rap", 324, &sss2};
    Song sss4 = {"Song15", "ArtistA", "Pop", 313, &sss3};
    Song sss5 = {"Song16", "ArtistB", "Pop", 235, &sss4};
    
    Song *sss = &sss5;

    cout << "Trying to split the third playlist from the first song: " << endl;
    Song* nsss = split(sss, 1);
    
    cout << "The playlist is now: " << endl;
    displayPlaylist(sss);
    cout << endl;
    cout << "The new playlist is:" << endl;
    displayPlaylist(nsss);
    cout << endl;

    return 0;
}
