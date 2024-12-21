#include "ex04-library.h"
#include <iostream>

using namespace std;

//Do not modify
template<class T>
mydeque<T>::mydeque() {
	size=0;
	first=nullptr;
	last=nullptr;
}

//Do not modify
template<class T>
int mydeque<T>::getSize() {
	return size;
}

//Do not modify
template<class T>
void mydeque<T>::print_front() {
	if(size==0){
		cout << "The deque is empty.\n";
	}
	else{
		cout << first->content <<"\n";
	}
}

//Do not modify
template<class T>
void mydeque<T>::print() {
	if(size==0){
		cout << "The deque is empty.\n";
	}
	else{
		cout << "The deque has size " << size << ":\n";
		Node<T> * current = 	first;
		while(current!=nullptr){
			cout << "  " <<current->content << "\n";
			current = current->next;
		}
	}
}

//Do not modify
template<class T>
void mydeque<T>::push_when_empty(T v) {
	Node<T> * node = new Node<T>;
	node->content=v;
	node->next=nullptr;
	first=node;
	last=node;
	size=1;
}

//Exercise 4 (a) Check and correct if necessary
template<class T>
mydeque<T>::~mydeque() {
	Node<T> * current = 	first;
	while(current!=nullptr){
		Node<T> * next = current->next;
		delete current;
		current = next;
	}
	cout << "Destructor completed\n";
}
/*
template<class T>
mydeque<T>::~mydequeWRONG() {
	Node<T> * current = 	first;
	while(current!=nullptr){
		delete current;
		Node<T> * next = current->next;
		current = next;
	}
}
*/

//Exercise 4 (b) Implement this function
template<class T>
void mydeque<T>::push_back(T v) {
	if(size==0){
		push_when_empty(v);
	}
	else{
		Node<T> * node = new Node<T>;
		node->content=v;
		node->next=nullptr;
		last->next = node;
		last=node;
		size++;
	}
}

//Exercise 4 (c) Implement this function
template<class T>
void mydeque<T>::push_front(T v) {
	if(size==0){
		push_when_empty(v);
	}
	else{
		Node<T> * node = new Node<T>;
		node->content=v;
		node->next=first;
		first = node;
		size++;
	}
}

//Exercise 4 (d) Check and correct if necessary
template<class T>
void mydeque<T>::print_back() {
	if(size==0){
		cout << "The deque is empty.\n";
	}
	else{
		cout << last->content <<"\n";
	}
}
/*
template<class T>
void mydeque<T>::print_backWRONG() {
//	if(size==0){
	if(size!=0){
		cout << "The deque is empty.\n";
	}
	else{
//		cout << last->content <<"\n";
		cout << first->content <<"\n";
	}
}
*/

//Exercise 4 (e) Complete the implementation of this function
template<class T>
bool mydeque<T>::pop_front() {
	if(size==0){
		//Cannot pop from an empty deque. I return false;
		return false;
	}
	else if(size==1){
		//Since size is 1, the deque becomes empty
		delete first;
		first=nullptr;
		last=nullptr;
		size=0;
		return true;
	}
	else{
		//Since the deque has at least 2 elements, the second element becomes the first one.
		//Complete this code
		Node<T> * node = first;
		first = first->next;
		delete node;
		size--;
		return true;
	}
	/*
	else{
		//Put your code here
	}
	*/
}

//Do not modify
template class mydeque<int>;
