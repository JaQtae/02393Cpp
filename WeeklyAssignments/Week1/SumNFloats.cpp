#include <iostream>

using namespace std;

int main() {
    int n;
    float number, result = 0;

    cout << "";
    cin >> n;

    for (int i = 0; i < n; ++i) { // declare start, rule and interval... Look more at this!
        cin >> number;
        result += number;
    }

    cout << result << endl;

    return 0;
}