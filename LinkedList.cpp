#include"LinkedList.h"
#include<iostream>
using namespace std;

LinkedList::LinkedList(): head(0){

}

//Add a new node with data as the start of the list
void LinkedList::prepend(int data){
	Node *n = new Node(data);
	n->setNext(head);
	head=n;
}

//insert a new node with data at the end of the list
//if the list is empty
void LinkedList::append(int data){
	//create a new node with data
	Node *n = new Node(data);
	//if empty list make the current node the head
	if(size()==0){
		//cout <<"Size is zero"<<"\n";
		head=n;
		return;
	}
	else{
		//cout <<"Size is non-zero"<<"\n";
		//create a node t that points to the head
		Node *t;
		t=head;
		//iterate until reaching the end
		while(t->getNext()!=0){
				t=t->getNext();
		}
		//make the new node the end node
		t->setNext(n);
		//cout <<"The value appended "<<n->getValue()<<"\n";
	}
}

//Remove the node at position pos
//Yet to be completed
void LinkedList::remove(int pos){
	//To be completed
	int s = size();
	if(s==0 or s< pos){
			cout<<"position specified is invalid as size= "<<s<<"pos= "<<pos<<"\n";
			throw pos;
	}
	//else throw pos;
}

//Return the size of the list
//function doesn't modify the instance and hence const
int LinkedList::size() const{
	int i=0;
	Node *t;
	t=head;
	//Iterate until the end of the list to
	//determine the size
	while(t!=0){
		++i;
		t=t->getNext();
	}
	return i;
}

//Print the contents of the linked list starting
//with the node pointed to by the head
void LinkedList::print() const {
	int i=1;
	Node *t;
	t=head;
	while(i<=size()){
		cout<<"The node # "<<i<<" is "<<t->getValue()<<"\n";
		t=t->getNext();
		++i;
	}

}

//Insert a new node at position pos with value val
//This method is yet to be completed
void LinkedList::insert(int pos, int val){
	Node *n = new Node(val);
	int s = size();
	throw pos;
	//To be completed
}

//read and return the contents of node at pos 
int LinkedList::fetch(int pos){
	//To be comnpleted
	//throw pos;
	return -10;
}

