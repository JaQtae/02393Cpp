#include <iostream>

using namespace std;

int main() {
    int count[1001] = {0}; // Array storing counts
    int val;

    while(true) {

        cin >> val;

        if (val == 0) {
            break;
        }

        if (val >= 1 && val <= 1000) {
            cout << count[val] << endl;
            count[val]++; // Increment count of value by 1
        } else {
            cout << "" << endl;
        }
    }

    return 0;
}