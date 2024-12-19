#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
GroceryList::GroceryList() {
    this->items.push_back("Lasagne");
    this->itemsInfo["Lasagne"] = {1, "With eggs if available"};

    this->items.push_back("Salmon");
    this->itemsInfo["Salmon"] = {500, "Smoked if available"};

    this->items.push_back("Spinach");
    this->itemsInfo["Spinach"] = {300, "Fresh"};

    this->items.push_back("Dessert");
    this->itemsInfo["Dessert"] = {8, "Maybe lagkage?"};
}

// Task 3(a).  Implement this method
void GroceryList::add(string name, unsigned int quantity, string notes) {
    // Write your code here
    for (auto it = this->items.begin(); it != items.end(); it++) {
        if (*it == name) {
            Info &item = this->itemsInfo[*it];
            item.quantity += quantity;
            item.notes += ";" + notes;
            return;
        }
    }
    // If we are here, the item was not in the grocery list
    this->items.push_back(name);
    this->itemsInfo[name] = {quantity, notes};
}

// Task 3(b).  Implement this method
bool GroceryList::remove(string name, unsigned int quantity) {
    // Write your code here
    for (auto it = this->items.begin(); it != this->items.end(); it++) {
        if (*it == name) {
            Info &item = this->itemsInfo[*it];
            if (item.quantity < quantity) {
                return false;
            }
            if (item.quantity == quantity) {
                itemsInfo.erase(name);
                items.erase(it);
                return true;
            }
            item.quantity -= quantity;
            return true;
        }
    }
    // If we are here, we did not find the item
    return false;
}

// Task 3(c).  Implement this method
bool GroceryList::copyEntry(string name, string newName) {
    // Write your code here
    if (this->itemsInfo.find(newName) != this->itemsInfo.end()) {
        return false; // newName is already in use
    }

    for (auto it = this->items.begin(); it != this->items.end(); it++) {
        if (*it == name) {
            this->items.push_back(newName);
            this->itemsInfo[newName] = this->itemsInfo[name];
            return true;
        }
    }
    // If we are here, the item being copied did not exist
    return false;
}

// Do not modify
void GroceryList::display() {
    // Write your code here
    for (auto it = this->items.begin(); it != this->items.end(); it++) {
        Info &item = this->itemsInfo[*it];
        cout << "name='" << *it << "'; ";
        cout << "quantity=" << item.quantity << "; ";
        cout << "notes='" << item.notes << "'" << endl;
    }
}