#include <iostream>
#include <vector>
#include <string>
#include "ex02-library.h"

using namespace std;

vector<string> match(vector<string> & u, vector<string> & v){
    
    vector<string> w;
    
    if (u.empty() || v.empty()) return w;
    
    if (u[0] == v[0]) {
        vector<string> u2(u.begin()+1,u.end());
        vector<string> v2(v.begin()+1,v.end());
        w = match(u2,v2);
        w.insert(w.begin(),u[0]);
        return w;
    }
    
    vector<string> u2(u.begin()+1,u.end());
    vector<string> w1 = match(u2,v);

    vector<string> v2(v.begin()+1,v.end());
    vector<string> w2 = match(u,v2);
    
    if (w1.size() > w2.size()) return w1;
    else return w2;
    
}

vector<string> read_until(string stop){
    vector<string> u;
    string e;
    while(true){
        cin >> e;
        if(cin.fail() || e == stop) break;
        u.push_back(e);
    }
    return u;
}

void display(vector<string> & u){
    for(unsigned int i=0; i<u.size(); i++) cout << u[i] << " " ;
    cout << endl;
}
