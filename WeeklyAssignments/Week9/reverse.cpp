#include <iostream> // cin cout
#include <vector>
#include <sstream> // stringstream
using namespace std;

void printReverse(const vector<int>& numbers, int idx) {
    if (idx < 0) {
        return; // Base case; No elements left to print
    }
    cout << numbers[idx] << " "; // Print the current element and a whitespace
    printReverse(numbers, idx - 1); // Recursion
}

int main() {
    string input;
    getline(cin, input); // "1 2 3 4 5" or "1 2 3 4 5 6 7 8 9 10" test cases;

    int num;
    vector<int> numbers;
    stringstream ss(input); // sstream object, because otherwise i can keep pressing enter until i give a non-integer input...


    while (ss >> num) {
        numbers.push_back(num);
    }
    printReverse(numbers, numbers.size() - 1); // Recursive call

    cout << endl;
    return 0;
}