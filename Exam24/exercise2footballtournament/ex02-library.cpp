#include <iostream>
#include "ex02-library.h"
using namespace std;

// -------------- Helper functions ----------------- //
// If t is null or not a match, returns nullptr
static TournamentNode *getMatchWinner(TournamentNode *t) {
    if (!t || t->nodeType != match) return nullptr;
    // if left scored more than right, left subtree wins; else right subtree wins
    return (t->leftPoints > t->rightPoints) ? t->left : t->right;
}

// If t is null or not a match, returns nullptr
static TournamentNode *getMatchLoser(TournamentNode *t) {
    if (!t || t->nodeType != match) return nullptr;
    // the opposite of getMatchWinner
    return (t->leftPoints < t->rightPoints) ? t->left : t->right;
}
// Recursively search t for a leaf‐node team with name == teamName.
// Returns the first encountered leaf pointer, or nullptr if not found.
static TournamentNode *findTeamNode(TournamentNode *t, const std::string &teamName) {
    if (!t) return nullptr;
    if (t->nodeType == team) {
        return (t->name == teamName) ? t : nullptr;
    }
    // Otherwise it's a match: search left & right
    TournamentNode *leftRes = findTeamNode(t->left, teamName);
    if (leftRes) return leftRes;
    return findTeamNode(t->right, teamName);
}
// Count how many matches a given team has actually played 
// (i.e., how many match‐nodes in which that team was one of the two participants).
// Note: if a team loses its first match, that single match counts.
// If the team progresses multiple rounds, you count each match it played in.
static unsigned int countMatchesPlayedByTeam(TournamentNode *t, const std::string &teamName) {
    if (!t) return 0;
    // If leaf
    if (t->nodeType == team) {
        // Leaf itself is not a match, so contributes 0
        return 0;
    }
    // t is a match. Check if teamName appears in left subtree or right subtree.
    bool inLeft  = (findTeamNode(t->left, teamName) != nullptr);
    bool inRight = (findTeamNode(t->right, teamName) != nullptr);
    unsigned int countHere = (inLeft || inRight) ? 1 : 0;
    // Recurse down both sides:
    return countHere
         + countMatchesPlayedByTeam(t->left, teamName)
         + countMatchesPlayedByTeam(t->right, teamName);
}
// Checks if team won a specific match
static bool didTeamWinMatch(TournamentNode *matchNode, const std::string &teamName) {
    if (!matchNode || matchNode->nodeType != match) return false;
    TournamentNode *winner = getMatchWinner(matchNode);
    // If the winner is a leaf‐node (team), check its name
    if (winner && winner->nodeType == team && winner->name == teamName) {
        return true;
    }
    return false;
}

static unsigned int countMatchesWonByTeam(TournamentNode *t, const std::string &teamName) {
    if (!t) return 0;
    if (t->nodeType == team) {
        return 0;
    }
    // t is a match
    unsigned int total = didTeamWinMatch(t, teamName) ? 1 : 0;
    total += countMatchesWonByTeam(t->left, teamName);
    total += countMatchesWonByTeam(t->right, teamName);
    return total;
}

static unsigned int findMaxScoreInAllMatches(TournamentNode *t) {
    if (!t) return 0;
    if (t->nodeType == team) return 0;
    unsigned int bestHere = std::max(t->leftPoints, t->rightPoints);
    unsigned int leftSub  = findMaxScoreInAllMatches(t->left);
    unsigned int rightSub = findMaxScoreInAllMatches(t->right);
    return std::max(bestHere, std::max(leftSub, rightSub));
}

static unsigned int findMinScoreInAllMatches(TournamentNode *t) {
    if (!t) return UINT_MAX;  
    if (t->nodeType == team) return UINT_MAX;
    // In this match, the losing score is min(leftPoints, rightPoints)
    unsigned int loseHere = std::min(t->leftPoints, t->rightPoints);
    unsigned int leftSub  = findMinScoreInAllMatches(t->left);
    unsigned int rightSub = findMinScoreInAllMatches(t->right);
    return std::min(loseHere, std::min(leftSub, rightSub));
}

static bool anyTeamHasScoreAbove(TournamentNode *t, unsigned threshold) {
    if (!t) return false;
    if (t->nodeType == team) return false;
    if (t->leftPoints >= threshold || t->rightPoints >= threshold) {
        return true;
    }
    return anyTeamHasScoreAbove(t->left, threshold)
        || anyTeamHasScoreAbove(t->right, threshold);
}

static string teamWonTournament(TournamentNode *t){
    if (t == nullptr || t->nodeType == team){
        return "";
    }
    // Recursively go into WINNING subtree or branch
    if (t->leftPoints > t->rightPoints) { // Left wins
        if (t->left->nodeType == team) { // if left isnt a match its a team
            return t->left->name; // get name
        }
        return winner(t->left); // else go deeper into the left subtree
    } 
    else { // Right wins
        if (t->right->nodeType == team) { // if right isnt a match its a team
            return t->right->name; // get name
        }
        return winner(t->right);
    } 
}
// -------------------------------------------------------------------------------
// – getMatchWinner(t) → returns pointer to the subtree (leaf or match) that won at node t.
// – getMatchLoser(t) → pointer to the subtree that lost.
// – findTeamNode(t, name) → pointer to leaf node if found, else nullptr.
// – countMatchesPlayedByTeam(t, name) → total number of match‐nodes involving name.
// – countMatchesWonByTeam(t, name) → total number of match‐nodes that name actually won.
// – findMaxScoreInAllMatches(t) → highest single‐team score across all matches.
// – findMinScoreInAllMatches(t) → lowest losing score across all matches.
// – anyTeamHasScoreAbove(t, threshold) → true if any match has a side ≥ threshold.

// Task 2(a).  Implement this function
string winner(TournamentNode *t) {
    return teamWonTournament(t);
}

// Task 2(b).  Implement this function
unsigned int highestScore(TournamentNode *t) {
    if (t == nullptr){
        return 0;
    }
    unsigned highest_score = findMaxScoreInAllMatches(t);
    return highest_score;
}


// Task 2(c).  Implement this function
bool lostAllMatches(TournamentNode *t, string teamName) {
    if (t == nullptr || t->nodeType == team) {
        return false;
    }
    unsigned nr_won_by_team = countMatchesWonByTeam(t, teamName);
    if (nr_won_by_team == 0){
        return true;
    }
    return false; // Placeholder return value
}
