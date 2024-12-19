#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
void displayTeams(TournamentNode *t) {
    // In-order traversion (slide ~21 week 12)
    // Traverse left descendants -> show current node content
    // -> traverse right
    // NOTE: Trees we can use the -> operator to access stuff (left, right, nodetype)
    if (t == nullptr) {
        return; // Base case: points to nothing, end of tree
    } else if (t->nodeType == team) {
        cout << t->name << endl; // Print team name
    } else {
        displayTeams(t->left); // Traverse left (all the way down)
        displayTeams(t->right); // then go back up and traverse right
    }
}

// Task 2(b).  Implement this function
unsigned int matches(TournamentNode *t) {
    // Replace the following with your code
    if ((t == nullptr) || (t->nodeType == team)) {
        return 0; // 0 if no node or its a team node
    }
    else { // Has to be a match
        // Recursion: + 1 if match found, 
        // continue down left and right of tree
        return 1 + matches(t->left) + matches(t->right);
    }
}

// Task 2(c).  Implement this function
string winner(TournamentNode *t) {
    // Replace the following with your code
    if (t == nullptr) {
        return "";
    } else if (t->nodeType == team) { // We have reached the bottom of traversing winners
        return t->name; 
    } else if(t->result == leftWin) { //Left won
        return winner(t->left); // Keep going left
    } else { // Right must have won
        return winner(t->right); // Go right
    }
}

// Task 2(d). Implement this function
bool wonAnyMatch(TournamentNode *t, string teamName) {
    // Replace the following with your code

    // true if VAR=teamName won AT LEAST ONE match in t
    // IF NOT 1 win or participate, return false

    // We ONLY need to concern ourselves with ONE particular team. 
    // So we can traverse entirety of tree to see if there's at least one matching!!!

    // Special case: t is nullptr or t->team: FALSE
    if (t==nullptr) {
        return false;
    } else if (t->nodeType == team) {
        return false;
    } 
    // A match node. Let's search for teamName input
    if (t->result == leftWin) { // They won first match?
        if (t->left->nodeType == team && t->left->name == teamName){ 
        // Go left. If team, we know we're at the end. Check if its the team name
            return true;
        } else { // Else: Did they win any left OR did they win right?
            return wonAnyMatch(t->left, teamName) || wonAnyMatch(t->right, teamName); 
        }
    } 
    else {// result is right won
        if (t->right->nodeType == team && t->right->name == teamName) {
            return true;
        } else { // Did they win in left or right side of tree?
            return wonAnyMatch(t->left, teamName) || wonAnyMatch(t->right, teamName); 
        }
    }
}
