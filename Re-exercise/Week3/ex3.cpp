#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Contact { // Designed Struct type for problem
    string firstName;
    string middleName;
    string lastName;
    string phoneNumber;
    string streetAddress;
    int houseNumber;
    int zipCode;
    string region;
};

int main() {
    const int N = 50; // Max no. pages
    vector<Contact> addressBook[N]; // Initialize a vector with the Contact structure type, call it adressBook and give it N pages (elements).
    string command; // User input command
    int page; // User input page

    while (cin >> command) { // Continuous input loop:

        if (command == "add") { // Take page, is it valid, input from behind w info.
            cin >> page;
            if (page >= 1 && page <= N && addressBook[page-1].empty()) { // Page is given 1->N, array is 0->N-1.
            // Given valid page, and it is empty, input the new contact info.
                Contact newContact; // newContact is a new Contact struct
                cin >> newContact.firstName >> newContact.middleName >> newContact.lastName
                    >> newContact.phoneNumber >> newContact.streetAddress >> newContact.houseNumber
                    >> newContact.zipCode >> newContact.region;
                addressBook[page - 1].push_back(newContact); // push_back() adds to end of vector.
            }
        } else if (command == "clr") { // Reset page
            cin >> page;
            if (page >= 1 && page <= N) {
                addressBook[page-1].clear();
            }
        } else if (command == "qry") { // | Find page -> if it isnt empty -> read Contact struct info |-> output comma seperate + newline termination
            cin >> page;
            if (page >= 1 && page <= N && !addressBook[page-1].empty()) {
                for (const Contact& contact : addressBook[page-1]) { // Iterate over contacts on page. [0] indexing didn't work??
                    cout << contact.firstName << "," << contact.middleName << "," << contact.lastName << ","
                         << contact.phoneNumber << "," << contact.streetAddress << "," << contact.houseNumber << ","
                         << contact.zipCode << "," << contact.region << " " << endl;
                }
            }
        } else if (command == "quit") {
            break;
        }
    }

    return 0;
}