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
    int scalar_product = 0;
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
    size_t max_size = max(a_values.size(), b_values.size()); // find largest
    // Used for iteration too!
    for (size_t i = 0; i < max_size; ++i) { //iterate over elements
        // if size of a is less than i, append value of a[i] for scalar_product
        // else append 0 (a.size() < b.size() <=> for each i b has more than a, append 0's)
        int get_a = (i < a_values.size()) ? a_values[i] : 0; // if i < a_values.size() then get a_values[i] else 0
        int get_b = (i < b_values.size()) ? b_values[i] : 0; // if i < b_values.size() then get b_values[i] else 0
        scalar_product += get_a * get_b; // add to scalar product
    }


    cout << scalar_product << endl;
    return 0;
}