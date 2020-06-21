#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node {
private:
	T elem;
	Node *next;

public:
	// -- CONSTRUCTORES --
	Node(Node &o);
	Node(T elem, Node *next = nullptr);

	// Setters/Getters
	void setElem(T elem);
	T getElem() const;

	void setNext(Node *next);
	Node *getNext() const;
};

// -- CONSTRUCTORES --
template <typename T>
Node<T>::Node(Node &o) {
	this->elem = o.elem;
	this->next = o.next;
}

template <typename T>
Node<T>::Node(T elem, Node *next) {
	this->elem = elem;
	this->next = next;
}

// Setters/Getters
template <typename T>
void Node<T>::setElem(T elem) {
	this->elem = elem;
}

template <typename T>
T Node<T>::getElem() const {
	return elem;
}

template <typename T>
void Node<T>::setNext(Node *next) {
	this->next = next;
}

template <typename T>
Node<T> *Node<T>::getNext() const {
	return next;
}

#endif