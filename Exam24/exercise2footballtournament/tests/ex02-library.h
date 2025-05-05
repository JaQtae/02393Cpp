#ifndef EX02_LIBRARY_H_
#define EX02_LIBRARY_H_

#include <string>

using namespace std;

enum NodeType { match, team };

struct TournamentNode {
    NodeType nodeType;

    string name; // Only used if nodetype == team

    unsigned int leftPoints;         // Only used if nodetype == match;
    unsigned int rightPoints;         // Only used if nodetype == match;
    TournamentNode *left;  // Only used if nodetype == match;
    TournamentNode *right; // Only used if nodetype == match;
};

string winner(TournamentNode *t);
unsigned int highestScore(TournamentNode *t);
bool lostAllMatches(TournamentNode *t, string teamName);

#endif /* EX02_LIBRARY_H_ */
