#include "Node.h"

Node::Node(int v) : value(v), next(0) {
}

void Node::setNext(Node* n) {
	next = n;
}

Node* Node::getNext() const {
	return next;
}

int Node::getValue() const {
	return value;
}

Node::~Node() {
}
