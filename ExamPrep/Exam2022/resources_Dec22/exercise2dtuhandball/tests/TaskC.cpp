#include <iostream>
#include <string>
#include "ex02-library.h"
using namespace std;

int main() {
    TournamentNode t0 = {team, "Biosustain", none, nullptr, nullptr};
    TournamentNode t1 = {team, "Offshore", none, nullptr, nullptr};
    TournamentNode t2 = {team, "Entrepreneurship", none, nullptr, nullptr};
    TournamentNode t3 = {team, "Chemical Engineering", none, nullptr, nullptr};
    TournamentNode t4 = {team, "Health Tech", none, nullptr, nullptr};
    TournamentNode t5 = {team, "Energy", none, nullptr, nullptr};

    // Initial matches
    TournamentNode m0 = {match, "", leftWin, &t0, &t5};
    TournamentNode m1 = {match, "", leftWin, &t1, &t4};
    TournamentNode m2 = {match, "", rightWin, &t2, &t3};

    // Semifinal
    TournamentNode s0 = {match, "", rightWin, &m0, &m2};

    // Final
    TournamentNode tournament = {match, "", rightWin, &s0, &m1};

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
