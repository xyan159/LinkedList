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
	}
	else{
		//cout <<"Size is non-zero"<<"\n";
		//create a node t that points to the head
		Node *t = head;
		//iterate until reaching the end
		while(t->getNext()!=0){
				t=t->getNext();
		}
		//make the new node the end node
		t->setNext(n);
		//cout <<"The value appended "<<n->getValue()<<"\n";
	}
  return;
}

//Remove the node at position pos, 1st element = 1 instead of 0
void LinkedList::remove(int pos){
	if(size() == 0 or size() < pos){
		cout<<"position specified is invalid as size= "<< size() << "pos= "<< pos << endl;
		throw pos; // exits the remove()
	}

  Node *t = head;
  //iterate until reaching the node before pos
  for( int i = 1; i < pos-1; i++) t=t->getNext();
    Node* toRemove = t->getNext(); //creates another pointer pointing to the node at pos for removal later
  if( toRemove != 0){
    t->setNext( toRemove->getNext()); //link t to the link after
    delete toRemove;
  } else {
    t->setNext(0); //link t to the link after
  }
  print();
}

//Return the size of the list
//function doesn't modify the instance and hence const
int LinkedList::size() const{
	int i=0;
	Node *t = head;
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
  if(size() == 0 or size() < pos){
		cout<<"position specified is invalid as size= "<< size() << "pos= "<< pos << endl;
		throw pos; // exits the remove()
	}
	Node *n = new Node(val);
  Node *t = head;
  //iterate until reaching the node before pos
  for( int i = 1; i < pos-1; i++) t=t->getNext();
  if( pos > 1){
    n->setNext(t->getNext()); //let the new node connects to the linked node at pos
    t->setNext(n); //link t (node before pos) to new node
  } else if( pos == 1){ //if inserting at the start
    n->setNext(head);
    head = n;
  }

}

//read and return the contents of node at pos 
int LinkedList::fetch(int pos){
  if(size() == 0 or size() < pos){
		cout<<"position specified is invalid as size= "<< size() << "pos= "<< pos << endl;
		throw pos; // exits the remove()
	}

  Node *t = head;
  //iterate until reaching  pos
  for( int i = 1; i < pos; i++) t = t->getNext();
  return t->getValue();
}

