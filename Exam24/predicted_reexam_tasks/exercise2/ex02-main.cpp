#include <iostream>
#include <vector>
#include "ex02-library.h"
using namespace std;

void printVector(const vector<string>& v) {
    for (const string& name : v) {
        cout << "- " << name << endl;
    }
}

int main() {
    // Teams
    TournamentNode t0 = {team, "Energy", 0, 0, nullptr, nullptr};
    TournamentNode t1 = {team, "Aqua", 0, 0, nullptr, nullptr};
    TournamentNode t2 = {team, "Compute", 0, 0, nullptr, nullptr};
    TournamentNode t3 = {team, "Space", 0, 0, nullptr, nullptr};

    // Initial matches
    TournamentNode m0 = {match, "", 1, 5, &t0, &t1}; // Winner: Aqua
    TournamentNode m1 = {match, "", 3, 1, &t2, &t3}; // Winner: Compute

    // Final match
    TournamentNode root = {match, "", 1, 2, &m0, &m1}; // Winner: Compute

    // allWinners
    cout << "Teams that won at least one match:" << endl;
    vector<string> winners = allWinners(&root);
    printVector(winners);

    // lowestScore
    unsigned int minScore = lowestScore(&root);
    cout << "Lowest score in any match: " << minScore << endl;

    // wonAllMatches tests
    vector<string> testTeams = {"Compute", "Aqua", "Energy", "Space", "Math"};
    for (const string& team : testTeams) {
        cout << "Has " << team << " won all its matches? ";
        cout << (wonAllMatches(&root, team) ? "Yes" : "No") << endl;
    }

    return 0;
}
