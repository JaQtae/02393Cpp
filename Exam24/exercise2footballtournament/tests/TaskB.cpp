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

    // Initial matches
    TournamentNode m0 = {match, "", 1, 3, &t0, &t5};
    TournamentNode m1 = {match, "", 2, 4, &t1, &t4};
    TournamentNode m2 = {match, "", 2, 1, &t2, &t3};

    // Semifinal
    TournamentNode s0 = {match, "", 0, 1, &m0, &m2};

    // Final
    TournamentNode tournament = {match, "", 3, 0, &s0, &m1};

    cout << "The highest score in an empty torunament is: ";
    cout << highestScore(nullptr) << endl;

    cout << "The highest score in one of the team nodes is: ";
    cout << highestScore(&t2) << endl;

    cout << "The highest score in one of the initial matches is: ";
    cout << highestScore(&m2) << endl;

    cout << "The highest score up to the semifinal is: ";
    cout << highestScore(&s0) << endl;

    cout << "The highest score in the tournament is: ";
    cout << highestScore(&tournament) << endl;

    return 0;
}
