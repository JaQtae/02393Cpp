#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Contact { // Designed Struct type 
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
    vector<Contact> addressBook[N];
    string command;
    int page;

    while (cin >> command) {
        if (command == "add") { // Take page, is it valid, input from behind w info.
            cin >> page;
            if (page >= 1 && page <= N && addressBook[page-1].empty()) {
                Contact newContact;
                cin >> newContact.firstName >> newContact.middleName >> newContact.lastName
                    >> newContact.phoneNumber >> newContact.streetAddress >> newContact.houseNumber
                    >> newContact.zipCode >> newContact.region;
                addressBook[page - 1].push_back(newContact);
            }
        } else if (command == "clr") { // Reset page
            cin >> page;
            if (page >= 1 && page <= N) {
                addressBook[page-1].clear();
            }
        } else if (command == "qry") { // Find page, if it isnt empty read Contact struct info and comma seperate + newline termination
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