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

    // Initial matches
    TournamentNode m0 = {match, "", leftWin, &t0, &t5};
    TournamentNode m1 = {match, "", rightWin, &t1, &t4};
    TournamentNode m2 = {match, "", leftWin, &t2, &t3};

    // Semifinal
    TournamentNode s0 = {match, "", rightWin, &m0, &m2};

    // Final
    TournamentNode tournament = {match, "", rightWin, &s0, &m1};

    cout << "The number of matches in an empty torunament is: ";
    cout << matches(nullptr) << endl;

    cout << "The number of matches in one of the team nodes is: ";
    cout << matches(&t2) << endl;

    cout << "The number of matches in one of the initial matches is: ";
    cout << matches(&m2) << endl;

    cout << "The number of matches up to the semifinal is: ";
    cout << matches(&s0) << endl;

    cout << "The number of matches in the tournament is: ";
    cout << matches(&tournament) << endl;

    return 0;
}
