#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool isPalindrome(const vector<int>& sequence, int left, int right) { // "Symmetrical" around middle element
    if (left >= right) return true; // Base case --> left and right pointers are equal, so were in the middle of sequence
    if (sequence[left] != sequence[right]) return false; // . IF elements are not equal, TERMINATE
    return isPalindrome(sequence, left + 1, right - 1); // go 1 step closer to the middle from each side. 
    // l=0, r=5-1: [1 2 3 2 1] -> [1]=[1]? !CONTINUE! -> l=1, r=3: [2 3 2] -> [2]=[2]? !CONTINUE! -> l=r=2: [3] -> BASE CASE: TRUE
    // [1 2 3 4 5] -> [1]=[5]? !FALSE! -> FALSE
}

int main() {
    vector<int> sequence;
    int num;
    string input;
    getline(cin, input);
    stringstream ss(input); // Terminate on enter...
    while (ss >> num) {
        sequence.push_back(num);
    }
    if (isPalindrome(sequence, 0, sequence.size() - 1)) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}