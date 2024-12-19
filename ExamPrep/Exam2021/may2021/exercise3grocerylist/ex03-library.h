#ifndef EX03_LIBRARY_H_
#define EX03_LIBRARY_H_

#include <string>
#include <vector>
#include <map>
using namespace std;

struct Info {
    unsigned int quantity;
    string notes;
};

class GroceryList {
private:
    vector<string> items;
    map<string,Info> itemsInfo;
public:
    GroceryList();
    void add(string name, unsigned int quantity, string notes);
    bool remove(string name, unsigned int quantity);
    bool copyEntry(string name, string newName);
    void display();
};

#endif /* EX03_LIBRARY_H_ */
