#include "ex04-library.h"
#include <iostream>

using namespace std;

//Do not modify
template<class T>
mystack<T>::mystack() {
	size=0;
	top=nullptr;
}

//Do not modify
template<class T>
int mystack<T>::getSize() {
	return size;
}

//Do not modify
template<class T>
void mystack<T>::print() {
	if(size==0){
		cout << "The stack is empty.\n";
	}
	else{
		cout << "The stack has size " << size << ":\n";
		Node<T> * current = top;
		while(current!=nullptr){
			cout << "  " <<current->content << "\n";
			current = current->next;
		}
	}
}


//Exercise 4 (a) Check and correct if necessary
template<class T>
mystack<T>::~mystack() {
	Node<T> * current = top;
	while(current!=nullptr){
		Node<T> * next = current->next;
		delete current;
		current = next;
	}
	cout << "Destructor completed\n";
}


/*
template<class T>
mystack<T>::~mystackWRONG() {
	Node<T> * current = top;
	while(current!=nullptr){
		delete current;
		Node<T> * next = current->next;
		current = next;
	}
	cout << "Destructor completed\n";
}
*/

//Exercise 4 (b) Implement this function
template<class T>
void mystack<T>::print_top() {
	if(size==0){
		cout << "The stack is empty.";
	}
	else{
		cout << top->content;
	}
}


//Exercise 4 (c) Implement this function
template<class T>
void mystack<T>::push(T v) {
	Node<T> * node = new Node<T>;
	node->content=v;
	node->next=top;
	top = node;
	size++;
}



//Exercise 4 (d) Implement this function
template<class T>
bool mystack<T>::pop() {
	if(size==0){
		//Cannot pop from an empty stack. I return false;
		return false;
	}
	else{
		//The stack can have 1 or more elements. By doing top = top->next, we set the second element as new top.
		//If there was just one element, we instead set top to nullptr.
		//Complete this code
		Node<T> * node = top;
		top = top->next;
		delete node;
		size--;
		return true;
	}
}

//Do not modify
template class mystack<int>;
