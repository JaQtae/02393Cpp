#include "ex03-library.h"
#include <iostream>

//Do not modify
WordsList::WordsList(){
	allWords.push_back("121");
	wordsToPalindromeDistance["121"]=0;
	allWords.push_back("122");
	wordsToPalindromeDistance["122"]=1;
}

//Exercise 3 (a) implement this method
void WordsList::print(){
	cout << allWords.size() << " words:";
	for(int i=0;i<allWords.size();i++){
		cout << " " <<allWords[i] << " (" << wordsToPalindromeDistance[allWords[i]]<<")";
	}
	cout << endl;
}

//Exercise 3 (b) implement this method
int WordsList::distancePalindrome(string s){
	int dist=0;
	int n=s.length()-1;
	for(int i=0;i<s.length()/2;i++,n--){
		if(s[i]!=s[n]){
			dist++;
		}
	}
	return dist;
}

//Exercise 3 (c) implement this method
void WordsList::addWord(string word){
	allWords.push_back(word);
	int dist = distancePalindrome(word);
	wordsToPalindromeDistance[word]=dist;
}

//Exercise 3 (d) implement this method
int WordsList::palindromeWords(){
	int count=0;
	for(int i=0;i<allWords.size();i++){
		if(wordsToPalindromeDistance[allWords[i]]==0){
			count++;
		}
	}
	return count;
}