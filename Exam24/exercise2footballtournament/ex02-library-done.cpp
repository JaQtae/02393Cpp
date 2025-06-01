#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
string winner(TournamentNode *t) {
    // if no pointers OR if we start with a team (its not a tournament then...)
    if (t == nullptr || t->nodeType == team) {
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

// Task 2(b).  Implement this function
unsigned int highestScore(TournamentNode *t) {
    // if no pointers OR if we start with a team (its not a tournament then...)
    // NOT STRICTLY TOLD TO CHECK TEAM, IF WE DONT ITS FINE, JUST ONE MORE RECURSION!!
    if (t == nullptr) { //|| t->nodeType == team) {
        return 0;
    }
    // This stores the maximum points seen so far, starting with the first match.
    // If we find any match in recursion, we will return the max points of that match.

    unsigned int currentMatch_max = max(t->leftPoints, t->rightPoints); // get current match max score
    
    unsigned int leftScore = highestScore(t->left); // get left score
    unsigned int rightScore = highestScore(t->right); // get right score
    
    // Compares the parent match score with the max of the left and right match children
    // and returns the maximum of all three. (bubbles up the previous cell!!!)
    return max(currentMatch_max, max(leftScore, rightScore)); 

    // Example from exam (sanity check):
    //         (1, 2)        <-- Root node: max(1,2) returns 2, recurse into left and right subtrees
    //        /      \ 
    //      (1, 5)   (3, 1)  <-- max(1,3) left and max(3,1) right both return 3, recurse
    //     /    \     /   \
    //    ()    ()   ()   () <-- it's a team node, so return 0

    // Left: returns max(5, 0, 0) = 5 --> sends to root node
    // Right: returns max(3, 0, 0) = 3 --> sends to root node
    // Root: returns max(2, max(5, 3)) = max(2, 5) = 5 --> sends to main function
    // So the highest score is 5.
}

// helper function to get the loser of a match
TournamentNode* pointerToLoser(TournamentNode* t) {
    // Finds the loser of a match and returns the pointer to the loser node.
    // IF there is no match, return nullptr.
    if (t == nullptr || t->nodeType != match) return nullptr;

    if (t->leftPoints < t->rightPoints) {
        return t->left; // left lost, so return left pointer
    } else {
        return t->right; // right lost
    }
}

// Task 2(c).  Implement this function
bool lostAllMatches(TournamentNode *t, string teamName) {
    if (t == nullptr || t->nodeType == team) {
        return false; // Special case
    }
    // Pointer to child node of side that lost the current match
    TournamentNode* loserNode = pointerToLoser(t);

    // Does loserNode contain queried info? (e.g. team node and has correct team name)
    bool lostThisMatch = (loserNode->nodeType == team && loserNode->name == teamName);

    // Recurse into next matches (left and right) to check if the team lost there too.
    bool lostInLeftSubtree = lostAllMatches(t->left, teamName);
    bool lostInRightSubtree = lostAllMatches(t->right, teamName);

    // If the team wins at any point, we return false via pointerToLoser.
    // We only return true if it lost in a tree with 1 match OR lost ALL matches.
    return lostThisMatch || lostInLeftSubtree || lostInRightSubtree;
    
// Example from exam (sanity check):
// Call 1: lostAllMatches(root) = false || Call 2 || Call 3 → true
//   -->    Call 2: lostAllMatches(left) = true || false || false → true
//   -->    Call 3: lostAllMatches(right) = false || false || false → false

// Example with win and lose:
// Call 1: match (1,2) — lostThisMatch = false (Since next node is a match!)
// ├── Call 2 (LEFT): match (1,5) — lostThisMatch = false (They won)
// │   ├── Energy — false (lost, but not the team we are looking for)
// │   └── Aqua — false (won)
// ├── Call 3 (RIGHT): match (3,1) — lostThisMatch = false
// │   ├── Compute — false (not team we are looking for)
// │   └── Space — false (not team we are looking for)
// Final return: false || false || false → false

}
