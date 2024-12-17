#include <iostream>

using namespace std;

int main() {
    int user_input;
    double counter[1000+1] = {0}; // Array storing counts from 1 to 1000 (inclusive)


    while(true) {
        cin >> user_input;

        if (user_input == 0) { // Base case; terminate if input int is 0.
            break;
        }

        if (user_input >= 1 && user_input <= 1000) {
            cout << "" << user_input << " was given " << counter[user_input] << " times before" << endl; // Print present count of user's input value
            counter[user_input]++; // Increment count of value by 1 (we've seen it once more)
        } 
    }

    return 0;


}