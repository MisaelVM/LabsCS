#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
private:
	int elem;
	Node *next;

public:
	// -- CONSTRUCTORES/DESTRUCTOR --
	Node();
	Node(Node &o);
	Node(int elem);

	// Setters/Getters
	void setElem(int elem);
	int getElem() const;

	void setNext(Node *next);
	Node *getNext() const;
};

#endif