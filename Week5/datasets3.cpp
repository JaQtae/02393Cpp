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

    // Scalar product
    int scalar_product = 0;
    size_t max_size = max(a_values.size(), b_values.size());

    for (size_t i = 0; i < max_size; ++i) {
        int a_val = (i < a_values.size()) ? a_values[i] : 0;
        int b_val = (i < b_values.size()) ? b_values[i] : 0;
        scalar_product += a_val * b_val;
    }

    cout << scalar_product << endl;
    return 0;
}
