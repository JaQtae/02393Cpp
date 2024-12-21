#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "ex03-library.h"

using namespace std;

void Dictionary::insert_words(string u, string v){
    
    if(   english2danish.find(u) == english2danish.end()
       && danish2english.find(u) == danish2english.end() ) {
    
        english2danish[u] = v;
        danish2english[v] = u;
        
    }
}

string Dictionary::get_word(string lang, string u){
    
    if(lang == "english") {
        if (english2danish.find(u) != english2danish.end())
            return english2danish[u];
        else
            return "#unknown#";
    }
        
    if(lang == "danish"){
        if (danish2english.find(u) != danish2english.end())
            return danish2english[u];
        else
            return "#unknown#";
    }
    
    return "#unknown#";
    
}

void Dictionary::insert_synonym(string lang, string u, string v){

    if(lang == "english"){
        english_synonyms[u].insert(v);
        english_synonyms[v].insert(u);
    }
        
    if(lang == "danish") {
        danish_synonyms[u].insert(v);
        danish_synonyms[v].insert(u);
    }

    return;

}

set<string> Dictionary::get_synonyms(string lang, string u){
    
    if(lang == "english") return english_synonyms[u];
    
    if(lang == "danish") return danish_synonyms[u];
    
    set<string> A;
    return A;

}

set<string> Dictionary::translate(string lang, string u){
    
    set<string> A;
    
    if(lang == "english"){
        if(english2danish.find(u) != english2danish.end()){
            A = danish_synonyms[english2danish[u]];
            A.insert(english2danish[u]);
        }
    }
    
    if(lang == "danish"){
        if(danish2english.find(u) != danish2english.end()){
            A = english_synonyms[danish2english[u]];
            A.insert(danish2english[u]);
        }
    }
    
    return A;
    
}