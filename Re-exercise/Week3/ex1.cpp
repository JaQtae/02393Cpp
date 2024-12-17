#include <iostream>
#include <set> // https://en.cppreference.com/w/cpp/container/set

using namespace std;

void get_integer_user_input(int& n) { // Passing n by reference to value in main()
    cin >> n;
};

int main() {
    int n;
    set<int> bag; // Initially empty bag for storage
    string command;

    while (cin >> command) { // Read the input command(s) 
        if (command == "add") {
            get_integer_user_input(n);
            bag.insert(n); // Insert the integer into the bag
        }
        else if (command == "del") {
            get_integer_user_input(n);
            bag.erase(n); // Erase the integer from the bag
        }
        else if (command == "qry") {
            get_integer_user_input(n);

            if (bag.find(n) != bag.end()) { // If the integer is found in the bag
                cout << "T"; // True
            } else {
                cout << "F"; // False
            }
        }
        else if (command == "quit") {
            break; // End the program
        }
    }

    return 0;

}