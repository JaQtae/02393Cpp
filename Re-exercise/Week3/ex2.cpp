#include <iostream>
#include <set> // https://en.cppreference.com/w/cpp/container/set

using namespace std;

void get_integer_user_input(int& n) { // Passing n by reference to value in main()
    cin >> n;
};

int main() {
    int n;
    multiset<int> bag; // multiset allows multiple instances of same element
    string command;

    while (cin >> command) { // Read the input command(s) 
        if (command == "add") {
            get_integer_user_input(n);
            bag.insert(n); // Insert the integer into the bag
        }
        else if (command == "del") {
            get_integer_user_input(n);
            
            // Now we need it to know it should delete one instance of the integer
            // Not all instances of the integer
            auto item = bag.find(n); // Find one instance of n in bag (auto assign type (int))
            if (item != bag.end()) { // If we find one. (bag.end() is returned if none are found!)
                bag.erase(item); // Delete it
            }
        }
        else if (command == "qry") {
            get_integer_user_input(n);

            if (bag.find(n) != bag.end()) { // If the integer is found in the bag (ie. not NOT found)
                cout << "T"; // True
            } else {
                cout << "F"; // False
            }
        }
        else if (command == "quit") {
            break; // Terminate program
        }
    }

    return 0;

}