#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    char id;
    int value;
    vector<int> a_values, b_values;
    string userInput;
    // Operate on per lline basis
    getline(cin, userInput);
    stringstream ss(userInput); // Give input line struct

    // Reading input continuously. (Needs end of input (EOL) to execute on enter)
    while (ss >> id >> value) {
        if (id == 'a') {
            a_values.push_back(value);
        } else if (id == 'b') {
            b_values.push_back(value);
        }
    }

    // Unsigned = Non-negative.
    // size_t is normally used for representing sizes of objects
    size_t max_size = max(a_values.size(), b_values.size());
    // Used for iteration too!
    for (size_t i = 0; i < max_size; ++i) {
        if (i < a_values.size()) {
            cout << a_values[i] << " ";
        }
        if (i < b_values.size()) {
            cout << b_values[i] << " ";
        }
    }


    cout << endl;
    return 0;
}