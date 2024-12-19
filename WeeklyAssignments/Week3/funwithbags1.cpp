#include <iostream>
#include <set> // https://en.cppreference.com/w/cpp/container/set

using namespace std;

int main() {
    set<int> bag; // Stores unique elements
    string command;
    int x;
    
    while (cin >> command) {
        if (command == "add") {
           cin >> x;
           bag.insert(x);
        }
        else if (command == "del") {
        cin >> x;
        bag.erase(x);
        }
        else if (command == "qry") {
        cin >> x;
        // if (bag.contains(x)) { (C++ 20)
        if (bag.find(x) != bag.end()) {
            cout << "T";
        } else {
            cout << "F";
        }
    }
        else if (command == "quit") {
            break;
        }
    }

    return 0;
}