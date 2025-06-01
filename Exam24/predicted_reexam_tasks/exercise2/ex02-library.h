#ifndef EX02_LIBRARY_H_
#define EX02_LIBRARY_H_

#include <string>
#include <vector>
using namespace std;

enum NodeType { match, team };

struct TournamentNode {
    NodeType nodeType;
    string name; // Only used if nodeType == team
    unsigned int leftPoints; // Only used if nodeType == match
    unsigned int rightPoints; // Only used if nodeType == match
    TournamentNode *left; // Only used if nodeType == match
    TournamentNode *right; // Only used if nodeType == match
};

// Re-exam predicted functions
vector<string> allWinners(TournamentNode *t);
unsigned int lowestScore(TournamentNode *t);
bool wonAllMatches(TournamentNode *t, string teamName);

#endif /* EX02_LIBRARY_H_ */