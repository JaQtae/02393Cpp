#include <iostream>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    if (n < 0) {
        cout << "n is less than 0. Wrong input" << endl;
        return 0;
    }
    // for (int i = 1; i <= n; ++i) { // Gaussian sum
    // // from i=1 -> N (n(n+1) / 2)
    //     result += i;
    // }
    // equivalently: result = n*(n+1)/2;
    result = n*(n+1)/2;
    cout << result << endl;
    return 0;
}