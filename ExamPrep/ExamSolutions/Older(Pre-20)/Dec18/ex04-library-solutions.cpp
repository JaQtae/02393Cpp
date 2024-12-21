#include "ex04-library.h"
#include <iostream>

using namespace std;

//Do not modify
template<class T>
void Node<T>::printNode(){
	cout << "Name: " << name << ", value: " << value ;
	cout << ", children: " << children.size() << endl;
}

//Exercise 4 (a) Check and correct if necessary
template<class T>
Node<T>::Node(string name, T value){
	this->name=name;
	this->value=value;
}

/*
Node::NodeWRONG(string name, T value){
}
*/

//Exercise 4 (b) Implement getName, getValue, and addChild
template<class T>
string Node<T>::getName(){
	return name;
}

template<class T>
T Node<T>::getValue(){
	return value;
}

template<class T>
void Node<T>::addChild(Node<T> * child){
	children.push_back(child);
}

//Exercise 4 (c) Implement this method
template<class T>
void Node<T>::printLeafNodes(){
	if(children.size() == 0){
		cout << this->name << ' ' << this->value << ' ';
	}
	else{
		for(int i=0; i<children.size();i++){
			children[i]->printLeafNodes();
		}
	}
}

//Exercise 4 (d) Implement this method
template<class T>
int Node<T>::countMembersOfSubTree(){
	int count = 1;
	for(int i=0; i<children.size();i++){
		count += children[i]->countMembersOfSubTree();
	}
	return count;
}

//Do not modify
template class Node<string>;