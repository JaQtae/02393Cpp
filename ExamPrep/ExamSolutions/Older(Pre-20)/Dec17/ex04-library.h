#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

/*
 * This struct represents a node of a linked list.
 * 	content is the element stored in this node
 * 	next is the pointer to the next node of the list (or nullptr if this is the last node)
 *
 * This data structure is generic: it provides support for elements of any type.
 */
template<class T>
struct Node{
	T content;
	Node<T> * next;
};


/*
 * We implement our own version of DEQUE, Double Ended Queue.
 * Similarly, e.g., to vectors, our DEQUE has dynamic size that can be expanded or contracted.
 * We can do this by adding element on both ends (either its front or its back).
 * Also, we allow to retrieve both the first or the last inserted element.
 *
 * This data structure is generic: it provides support for collections of elements of any type.
 */
template <class T>
class mydeque {
private:
	/*
	 * Pointers to the first and last element of the deque
	 */
	Node<T> * first;
	Node<T> * last;

	/*
	 * Number of elements stored in the deque
	 */
	int size;

public:

	//Do not modify
	/*
	 * Add an element to the deque in the special case in which the deque is empty.
	 * This is a private method that has to be invoked both by push_back and push_front when the deque is empty
	 * This method should be private. We made it public to ease the development of tests.
	 */
	void push_when_empty(T v);

	//Do not modify
	/*
	 * Construct an empty deque
	 */
	mydeque();

	//Exercise 4 (a) Check and correct if necessary
	/*
	 * Deallocate all memory dynamically allocated for the deque
	 */
	~mydeque();

	//Do not modify
	/*
	 * Return the number of elements in the deque
	 */
	int getSize();

	//Do not modify
	/*
	 * Prints in console the first element of the deque without modifying the deque (hence size does not change).
	 * Note: the method prints just the element, without any further text
	 * Special cases:
	 * 	If the method is invoked on a empty deque, then the method prints an error message.
	 */
	void print_front();

	//Given
	/*
	 * Print information on the list
	 */
	void print();

	//Exercise 4 (b) Implement this function
	/*
	 * Add an element v at the end of the deque
	 * This element will hence be the new last element of the deque
	 * Special cases:
	 * 	If the method is invoked on a empty deque, then this method only invokes the private method push_when_empty
	 */
	void push_back(T v);

	//Exercise 4 (c) Implement this function
	/*
	 * Add an element at the beginning of the deque.
	 * This element will hence be the new first element of the deque
	 * Special cases:
	 * 	If the method is invoked on a empty deque, then this method only invokes the private method push_when_empty
	 */
	void push_front(T v);

	//Exercise 4 (d) Implement this function
	/*
	 * Prints in console the last element of the deque without modifying the deque (hence size does not change).
	 * Note: the method prints just the element, without any further text
	 * Special cases:
	 * 	If the method is invoked on a empty deque, then the method prints an error message.
	 */
	void print_back();

	//Exercise 4 (e) Complete the implementation of this function
	/*
	 * Removes the first element in the deque, effectively reducing the deque size by one.
	 * Memory allocated to store the element in the deque is deallocated.
	 * Special cases:
	 * 	If the method is invoked on an empty deque, nothing is done, and the value false is returned, meaning that the pop failed.
	 * 	If the method is invoked on a non-empty deque, the value true is returned, meaning that the pop succeeded'
	 */
	bool pop_front();

};
#endif /* EX04_LIBRARY_H_ */
