#include <iostream> 
using namespace std;

int main() {
    int n;
    float number, result = 0; // Start 0
    cin >> n;

    for (int i = 0; i < n; ++i) { // Start | Rule (i has to be less than n) | Increment 
        cin >> number; // Read in next number
        result += number; // Add it to the result
    }

    cout << result << endl; // Print final result
    return 0;
}