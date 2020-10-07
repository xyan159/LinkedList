/*****
 * A singly linked list class
 * Author: Partha Roop
 */

#include "Node.h"


class LinkedList{
private:
	Node *head;
public:
	//constructors
	LinkedList();
	//constructs a new linked list pointed to by start
	LinkedList(Node *start);
	//insert a new node with data in position pos in the list
	void insert(int pos, int data);
	//insert a new node with data at the end of the list
	void append(int data);
	//insert a new node with data at the start of the list
	void prepend(int data);
	//remove a node in position pos in the list
	void remove(int pos);
	//read the contents of node at pos
	int fetch(int pos);
	//return the number of nodes in the list
	int size() const;
	//print the contents of the list starting from the first node
	void print() const;
};
