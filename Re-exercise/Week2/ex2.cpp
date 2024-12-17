#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 0) {
        cout << "n is less than 0. Wrong input" << endl;
        return 0;
    }
    // Primes are only divisible by 1 and themselves
    // Even factors
    while (n % 2 == 0) { // Divisible by 2, lowest primes are (2, 3, 5, ...)
        cout << 2; // Even numbers become 2
        n /= 2; // Divide original input (e.g. 60) by 2. 60 / 2 = 30. This is the new n
        if (n != 1) cout << " * "; // If new n is not 1, we have more factors to find
    }
    
    // Odd primes. 
    for (int i = 3; i <= n; i += 2) { 
        while (n % i == 0) { // Increment till we reach a sub-odd prime n.
            cout << i; // Print the lowest prime factor of that number n
            n /= i; // Get that new n, e.g. (60 / [2] = 30) / [2] = 15 / [3] = 5 / [5] = 0
                    // where [<prime>] is the prime factor of the number n
            if (n != 1) cout << " * ";
        }
    }
    cout << endl;

    return 0;
}