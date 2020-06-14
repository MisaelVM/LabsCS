#include "Node.h"

// -- CONSTRUCTORES/DESTRUCTOR --
Node::Node() {
	elem = 0;
	next = nullptr;
}

Node::Node(Node &o) {
	this->elem = o.elem;
	this->next = o.next;
}

Node::Node(int elem) {
	this->elem = elem;
	this->next = nullptr;
}

// Setters/Getters
void Node::setElem(int elem) {
	this->elem = elem;
}

int Node::getElem() const {
	return elem;
}

void Node::setNext(Node *next) {
	this->next = next;
}

Node *Node::getNext() const {
	return next;
}