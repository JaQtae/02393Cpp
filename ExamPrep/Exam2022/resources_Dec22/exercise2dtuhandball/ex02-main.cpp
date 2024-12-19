#include <iostream>
#include "ex02-library.h"
using namespace std;

int main() {
    TournamentNode t0 = {team, "Aqua", none, nullptr, nullptr};
    TournamentNode t1 = {team, "Compute", none, nullptr, nullptr};
    TournamentNode t2 = {team, "Energy", none, nullptr, nullptr};
    TournamentNode t3 = {team, "Space", none, nullptr, nullptr};

    // Initial matches
    TournamentNode m0 = {match, "", rightWin, &t0, &t1};
    TournamentNode m1 = {match, "", leftWin, &t2, &t3};

    // Final match
    TournamentNode t = {match, "", leftWin, &m0, &m1};

    cout << "The teams in the tournament are: " << endl;
    displayTeams(&t);

    cout << endl << "The number of matches is: " << matches(&t) << endl;

    cout << "The winner of the tournament is: " << winner(&t) << endl;

    cout << "Did DTU Energy win any match? ";
    if (wonAnyMatch(&t, "Energy")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Did DTU Space win any match? ";
    if (wonAnyMatch(&t, "Space")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Did DTU Physics win any match? ";
        if (wonAnyMatch(&t, "Physics")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    return 0;
}
