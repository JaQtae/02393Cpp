#include <iostream>
#include <string>
#include "ex02-library.h"
using namespace std;

int main() {
    TournamentNode t0 = {team, "Sustain", 0, 0, nullptr, nullptr};
    TournamentNode t1 = {team, "Offshore", 0, 0, nullptr, nullptr};
    TournamentNode t2 = {team, "Skylab", 0, 0, nullptr, nullptr};
    TournamentNode t3 = {team, "Learn for Life", 0, 0, nullptr, nullptr};
    TournamentNode t4 = {team, "Space", 0, 0, nullptr, nullptr};
    TournamentNode t5 = {team, "Physics", 0, 0, nullptr, nullptr};
    TournamentNode t6 = {team, "Management", 0, 0, nullptr, nullptr};
    TournamentNode t7 = {team, "Wind", 0, 0, nullptr, nullptr};

    // Initial matches
    TournamentNode m0 = {match, "", 1, 3, &t0, &t5};
    TournamentNode m1 = {match, "", 0, 2, &t1, &t4};
    TournamentNode m2 = {match, "", 3, 2, &t2, &t6};
    TournamentNode m3 = {match, "", 1, 0, &t3, &t7};

    // Semifinals
    TournamentNode s0 = {match, "", 3, 1, &m0, &m2};
    TournamentNode s1 = {match, "", 2, 3, &m1, &m3};

    // Final
    TournamentNode t = {match, "", 1, 2, &s0, &s1};

    cout << "Has DTU Offshore lost all the matches in an empty tournament? ";
        if (lostAllMatches(nullptr, "Offshore")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Has DTU Offshore lost all the matches in a team node? ";
        if (lostAllMatches(&t1, "Offshore")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Has DTU Offshore lost all the matches in the tournament? ";
        if (lostAllMatches(&t, "Offshore")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Has DTU Skylab lost all the matches in the tournament? ";
        if (lostAllMatches(&t, "Skylab")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Has DTU Management lost all the matches in the tournament? ";
        if (lostAllMatches(&t, "Management")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    return 0;
}
