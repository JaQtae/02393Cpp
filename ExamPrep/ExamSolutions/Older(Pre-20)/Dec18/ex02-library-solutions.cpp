#include "ex02-library.h"
#include <iostream>

//Do not modify
int Node::countChildren(){
	return children.size();
}

//Exercise 2 (a) Implement the constructor and getName()
Node::Node(string name){
	this->name=name;
}

string Node::getName(){
	return name;
}

//Exercise 2 (b) Implement this method
void Node::addChild(Node * child){
	children.push_back(child);
}

//Exercise 2 (c) Check and correct if necessary
void Node::printParentNodes(){
	if(children.size() > 0){
		cout << this->name << ' ';
	}
	for(int i=0; i<children.size();i++){
		children[i]->printParentNodes();
	}
}

/*
void Node::printParentNodesWRONG(){
	for(int i=0; i<children.size()-1;i++){
		children[i]->printParentNodes();
	}
	cout << this->name << ' ';
}

*/

//Exercise 2 (d) Implement this method
void Node::printMembersOfSubTree(int generation){
	cout << this->name << ' ' << generation << ' ';
	for(int i=0; i<children.size();i++){
		children[i]->printMembersOfSubTree(generation+1);
	}
}
