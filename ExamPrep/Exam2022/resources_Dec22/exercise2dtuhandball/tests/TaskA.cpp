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
    TournamentNode tournament = {match, "", rightWin, &s0, &s1};

    cout << "The teams in an empty torunament are: " << endl;
    displayTeams(nullptr);
    cout << endl;

    cout << "The teams in one of the team nodes are: " << endl;
    displayTeams(&t3);
    cout << endl;

    cout << "The teams in one of the initial matches are: " << endl;
    displayTeams(&m2);
    cout << endl;

    cout << "The teams leading to one of the semifinals are: " << endl;
    displayTeams(&s0);
    cout << endl;

    cout << "The teams in the tournament are: " << endl;
    displayTeams(&tournament);

    return 0;
}
