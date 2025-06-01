// Exercise 2: Tournament predicted re-exam tasks
#include <string>
#include <vector>
#include <unordered_set>
#include <climits>
#include <algorithm>
using namespace std;

enum NodeType { match, team };

struct TournamentNode {
    NodeType nodeType;
    string name;
    unsigned int leftPoints, rightPoints;
    TournamentNode *left, *right;
};

void collectWinners(TournamentNode *t, unordered_set<string> &winners) {
    if (!t || t->nodeType == team) return;
    TournamentNode* winNode = (t->leftPoints > t->rightPoints) ? t->left : t->right;
    if (winNode->nodeType == team) winners.insert(winNode->name);
    else collectWinners(winNode, winners);
    collectWinners(t->left, winners);
    collectWinners(t->right, winners);
}

vector<string> allWinners(TournamentNode *t) {
    unordered_set<string> winnerSet;
    collectWinners(t, winnerSet);
    return vector<string>(winnerSet.begin(), winnerSet.end());
}

unsigned int lowestScore(TournamentNode *t) {
    if (!t || t->nodeType == team) return UINT_MAX;
    unsigned int currentMin = min(t->leftPoints, t->rightPoints);
    return min(currentMin, min(lowestScore(t->left), lowestScore(t->right)));
}

bool wonAllMatches(TournamentNode *t, string teamName) {
    if (!t || t->nodeType == team) return false;
    bool playedHere = false, wonHere = true;
    if (t->left->nodeType == team && t->left->name == teamName) {
        playedHere = true;
        wonHere = t->leftPoints > t->rightPoints;
    } else if (t->right->nodeType == team && t->right->name == teamName) {
        playedHere = true;
        wonHere = t->rightPoints > t->leftPoints;
    }
    if (playedHere && !wonHere) return false;
    bool leftResult = wonAllMatches(t->left, teamName);
    bool rightResult = wonAllMatches(t->right, teamName);
    return playedHere ? (leftResult && rightResult) : (leftResult || rightResult);
}
