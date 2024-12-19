#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int levenshteinDistance(string u, string v) {
    // Base cases if v or u empty
    if (u.empty()) return v.size();
    if (v.empty()) return u.size();
    
    int f = (u[0] == v[0]) ? 0 : 1; // If first elements are equal then f = 0 else f = 1

    return min({
        levenshteinDistance(u.substr(1), v) + 1, // remove first element of u, or equivalently, view all but first element of u, see reverse.cpp
        levenshteinDistance(u, v.substr(1)) + 1,
        levenshteinDistance(u.substr(1), v.substr(1)) + f 
    });
}

int main() {
    string u, v;
    cin >> u >> v;
    cout << levenshteinDistance(u, v);
    return 0;
}
