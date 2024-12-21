#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "ex03-library.h"

using namespace std;

Dictionary::Dictionary(void){
    words.resize(2);
    synonyms.resize(2);
}

void Dictionary::insert_words(string u, string v){
    words[0][u] = v;
    words[1][v] = u;
}

string Dictionary::get_word(int lang, string u){
    if (lang < 0 || lang > 1) return "";
    return words[lang][u];
}

void Dictionary::insert_synonym(int lang, string u, string v){
    if (lang < 0 || lang > 1) return;
    synonyms[lang][u].insert(v);
    synonyms[lang][v].insert(u);
}

set<string> Dictionary::translate(int lang, string u){
    
    set<string> A;
    
    if (lang < 0 || lang > 1) return A;
    
    if(words[lang].find(u) != words[lang].end()){
        A.insert(words[lang][u]);
        for (auto v : get_synonyms((lang+1)%2,words[lang][u])) A.insert(v);
        for (auto v : get_synonyms(lang,u)){
            A.insert(words[lang][v]);
            for (auto w : get_synonyms((lang+1)%2,words[lang][v])) A.insert(w);
        }
    }
    
    return A;
}

set<string> Dictionary::get_synonyms(int lang, string u){
    set<string> A;
    if (lang < 0 || lang > 1) return A;
    else return synonyms[lang][u];
}