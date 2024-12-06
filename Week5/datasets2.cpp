#include <iostream>
#include <vector>
using namespace std;

int main() {
    char id;
    int value;
    vector<int> a_values, b_values;

    while (cin >> id >> value) {
        if (id == 'a') {
            a_values.push_back(value);
        } else if (id == 'b') {
            b_values.push_back(value);
        }
    }

    size_t max_size = max(a_values.size(), b_values.size());

    // Interleaving output
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