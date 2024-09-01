#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Even factors
    while (n % 2 == 0) {
        cout << 2;
        n /= 2;
        if (n != 1) cout << " * ";
    }
    
    // Odd factors
    for (int i = 3; i <= n; i += 2) {
        while (n % i == 0) {
            cout << i;
            n /= i;
            if (n != 1) cout << " * ";
        }
    }

    cout << endl;
    
    return 0;
}