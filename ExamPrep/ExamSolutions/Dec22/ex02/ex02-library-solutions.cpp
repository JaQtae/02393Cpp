#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
void displayTeams(TournamentNode *t) {
    if (t == nullptr) {
        return; // Nothing to show
    } else if (t->nodeType == team) {
        cout << t->name << endl;
    } else {
        displayTeams(t->left);
        displayTeams(t->right);
    }
}

// Task 2(b).  Implement this function
unsigned int matches(TournamentNode *t) {
    if (t == nullptr) {
        return 0;
    } else if (t->nodeType == team) {
        return 0;
    } else {
        return 1 + matches(t->left) + matches(t->right);
    }
}

// Task 2(c).  Implement this function
string winner(TournamentNode *t) {
    if (t == nullptr) {
        return "";
    } else if (t->nodeType == team) {
        return t->name;
    } else if (t->result == leftWin) {
        return winner(t->left);
    } else {
        return winner(t->right);
    }
}

// Task 2(d). Implement this function
bool wonAnyMatch(TournamentNode *t, string teamName) {
    if (t == nullptr) {
        return false;
    } else if (t->nodeType == team) {
        return false;
    }

    // If we are here, the current node is a match
    if (t->result == leftWin) {
        if (t->left->nodeType == team && t->left->name == teamName) {
            return true; // The team won its very first match
        } else {
            return wonAnyMatch(t->left, teamName) || wonAnyMatch(t->right, teamName);
        }
    } else { // We have t->result == rightWin
        if (t->right->nodeType == team && t->right->name == teamName) {
            return true; // The team won its very first match
        } else {
            return wonAnyMatch(t->left, teamName) || wonAnyMatch(t->right, teamName);
        }
    }
}
