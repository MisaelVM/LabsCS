#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
private:
	int size;
	Node *head;

	void printNodesRecursively(Node *node);

public:
	// -- CONSTRUCTORES/DESTRUCTOR --
	LinkedList();
	LinkedList(LinkedList &o);
	LinkedList(int size, Node *head);
	~LinkedList();

	// Funciones
	void insert(const int elemento);
	void remove(const int elemento);
	void print();
	void printRecursive();
};

#endif