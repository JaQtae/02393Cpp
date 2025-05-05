#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
string winner(TournamentNode *t) {
    // if no pointers, empty
    string win_team = "";
    if (t == nullptr) {
        return "";
    }

    if (t->nodeType == match) { // if match
        if (t->leftPoints > t->rightPoints) { //most points side?
            return winner(t->left); // traverse side w most points
        } else {
            return winner(t->right);
        }
    }
    if (t->nodeType == team){
        win_team = t->name; // idk...
    }
    return win_team;
}

// Task 2(b).  Implement this function
unsigned int highestScore(TournamentNode *t) {
    if (t == nullptr) {
        return 0;
    }
    if (t->nodeType == match && (t->rightPoints > t->leftPoints)) {
        if (t->right->nodeType == team){
            return t->rightPoints;
        } else {
            return highestScore(t->right);
        }
    } else if (t->nodeType == match && (t->rightPoints < t->leftPoints)) {
        if (t->left->nodeType == team) {
            return t->leftPoints;
        } else {
            return highestScore(t->left);
        }
    }
}

// Task 2(c).  Implement this function
bool lostAllMatches(TournamentNode *t, string teamName) {
    if (t == nullptr) {
        return false;
    } else if (t->nodeType == team) {
        return true;
    }
    // I am missing some special case..


    if (t->leftPoints < t->rightPoints) {
        // Loser is left
        if (t->left->nodeType == team && t->left->name == teamName) {
            // Under match node is team, and it has teamName we query for
            return true;
        } else { // otherwise, traverse tree 
            return lostAllMatches(t->left, teamName);
        } 
    } else { // right lost
        if (t->right->nodeType == team && t->right->name == teamName) {
            return true; 
        } else {
            return lostAllMatches(t->right, teamName);
        }
    }

}
