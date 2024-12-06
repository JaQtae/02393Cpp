#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    char id;
    int value;
    vector<int> a_values, b_values;

    // Reading input
    while (cin >> id >> value) {
        if (id == 'a') {
            a_values.push_back(value);
        } else if (id == 'b') {
            b_values.push_back(value);
        }
    }

    // Sorting
    sort(a_values.begin(), a_values.end());
    sort(b_values.begin(), b_values.end());

    // Output a values
    for (int val : a_values) {
        cout << val << " ";
    }

    // Output b values
    for (int val : b_values) {
        cout << val << " ";
    }

    cout << endl;
    return 0;
}