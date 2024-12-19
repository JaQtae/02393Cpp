#include <iostream>
#include <string>
#include "ex02-library.h"
using namespace std;

int main() {
    TournamentNode t0 = {team, "Sustain", none, nullptr, nullptr};
    TournamentNode t1 = {team, "Offshore", none, nullptr, nullptr};
    TournamentNode t2 = {team, "Skylab", none, nullptr, nullptr};
    TournamentNode t3 = {team, "Learn for Life", none, nullptr, nullptr};
    TournamentNode t4 = {team, "Space", none, nullptr, nullptr};
    TournamentNode t5 = {team, "Physics", none, nullptr, nullptr};
    TournamentNode t6 = {team, "Management", none, nullptr, nullptr};
    TournamentNode t7 = {team, "Wind", none, nullptr, nullptr};

    // Initial matches
    TournamentNode m0 = {match, "", leftWin, &t0, &t5};
    TournamentNode m1 = {match, "", rightWin, &t1, &t4};
    TournamentNode m2 = {match, "", leftWin, &t2, &t6};
    TournamentNode m3 = {match, "", rightWin, &t3, &t7};

    // Semifinals
    TournamentNode s0 = {match, "", rightWin, &m0, &m2};
    TournamentNode s1 = {match, "", leftWin, &m1, &m3};

    // Final
    TournamentNode t = {match, "", rightWin, &s0, &s1};

    cout << "Did DTU Skylab win any match in an empty tournament? ";
        if (wonAnyMatch(nullptr, "Skylab")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Did DTU Skylab win any match in a team node? ";
        if (wonAnyMatch(&t2, "Skylab")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Did DTU Skylab win any match in the tournament? ";
        if (wonAnyMatch(&t, "Skylab")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Did DTU Offshore win any match in the tournament? ";
        if (wonAnyMatch(&t, "Offshore")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Did DTU Energy win any match in the tournament? ";
        if (wonAnyMatch(&t, "Energy")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    return 0;
}
