#ifndef EX02_LIBRARY_H_
#define EX02_LIBRARY_H_

#include <string>

enum NodeType { match, team };
enum Result { leftWin, rightWin, none };

struct TournamentNode {
    NodeType nodeType;

    std::string name; // Only used if nodetype == team

    Result result;         // Only used if nodetype == match;
    TournamentNode *left;  // Only used if nodetype == match;
    TournamentNode *right; // Only used if nodetype == match;
};

void displayTeams(TournamentNode *t);
unsigned int matches(TournamentNode *t);
std::string winner(TournamentNode *t);
bool wonAnyMatch(TournamentNode *t, std::string teamName);

#endif /* EX02_LIBRARY_H_ */
