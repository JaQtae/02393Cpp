#include <iostream>
#include <vector>
#include <string>
#include "ex02-library.h"

using namespace std;

vector<string> match(vector<string> & u, vector<string> & v){
    
    vector<string> w;
    
    if (u.empty() || v.empty()) return w;
    
    if (u[u.size()-1] == v[v.size()-1]) {
        vector<string> u2(u.begin(),u.end()-1);
        vector<string> v2(v.begin(),v.end()-1);
        w = match(u2,v2);
        w.push_back(u[u.size()-1]);
        return w;
    }
    
    vector<string> u2(u.begin(),u.end()-1);
    vector<string> w1 = match(u2,v);

    vector<string> v2(v.begin(),v.end()-1);
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
