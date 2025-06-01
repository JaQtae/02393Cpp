#include <iostream>
#include <string>
#include "../ex02-library.h"
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
    TournamentNode m2 = {match, "", 4, 5, &t2, &t6};
    TournamentNode m3 = {match, "", 1, 0, &t3, &t7};

    // Semifinals
    TournamentNode s0 = {match, "", 3, 1, &m0, &m2};
    TournamentNode s1 = {match, "", 2, 3, &m1, &m3};

    // Final
    TournamentNode tournament = {match, "", 1, 2, &s0, &s1};

    cout << "The winner of an empty torunament is: ";
    cout << winner(nullptr) << endl;

    cout << "The winner in one of the team nodes is: ";
    cout << winner(&t5) << endl;

    cout << "The winner of one of the initial matches is: ";
    cout << winner(&m1) << endl;

    cout << "The winner of the semifinal is: ";
    cout << winner(&s0) << endl;

    cout << "The winner of the tournament is: ";
    cout << winner(&tournament) << endl;

    return 0;
}
