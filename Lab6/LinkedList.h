#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList {
private:
	int size;
	Node<T> *head;
	Node<T> *tail;

	void printNodesRecursively(Node<T> *node);

public:
	// -- CONSTRUCTORES/DESTRUCTOR --
	LinkedList();
	LinkedList(LinkedList &o);
	LinkedList(const int element);
	~LinkedList();

	// Funciones
	void insert(const T element);
	void remove(const T element);
	void print();
	void printRecursive();

	void poptHead();
	void popTail();

	// --- ITERATOR PATTERN DECLARATION --- //
	class Iterator {
		friend class LinkedList;
	private:
		Node<T> *nodePointer;
		Iterator(Node<T> *initialLocation) { nodePointer = initialLocation; }

	public:
		Iterator() { nodePointer = nullptr;	}

		// Overload comparison operator ==
		bool operator == (const Iterator &iter) const {
			return nodePointer == iter.nodePointer;
		}

		// Overload comparison operator !=
		bool operator != (const Iterator &iter) const {
			return !(*this == iter);
		}

		// Overload assignment operator =
		Iterator &operator = (const Iterator &iter) {
			if (this != &iter)
				*nodePointer = *iter.nodePointer;
			return *this;
		}

		// Overloading operator prefix ++
		Iterator &operator ++ () {
			nodePointer = nodePointer->getNext();
			return *this;
		}

		// Overloading operator postfix ++
		Iterator &operator ++ (int) {
			Iterator iterCopy = *this;
			nodePointer = nodePointer->getNext();
			return iterCopy;
		}

		// Overloading dereference operator *
		const T &operator * () const {
			return nodePointer->getElem();
		}
	};

	Iterator begin() const { return Iterator(head); }
	Iterator end() const { return nullptr; }
};

// -- CONSTRUCTORES/DESTRUCTOR --
template <typename T>
LinkedList<T>::LinkedList() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList &o) {
	this->size = o.size;
	this->head = new Node<T>(o.head->getElem());
	Node<T> *thisNodePointer = head;
	Node<T> *objectNodePointer = o.head;
	while (objectNodePointer->getNext()) {
		thisNodePointer->setNext(new Node<T>(objectNodePointer->getNext()->getElem()));
		objectNodePointer = objectNodePointer->getNext();
		thisNodePointer = thisNodePointer->getNext();
	}
	this->tail = thisNodePointer;
}

template <typename T>
LinkedList<T>::LinkedList(const int element) {
	this->size = 1;
	this->head = new Node<T>(element);
	this->tail = head;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	Node<T> *nodePointer = head;
	while (nodePointer) {
		Node<T> *nextNode = nodePointer->getNext();
		delete nodePointer;
		nodePointer = nextNode;
	}
}

// Funciones
template <typename T>
void LinkedList<T>::insert(const T element) {
	Node<T> *newNode = new Node<T>(element);
	if (!head) { // Lista vacia
		head = newNode;
		tail = newNode;
	}
	else {
		Node<T> *previousNode = nullptr;
		Node<T> *nodePointer;
		for (nodePointer = head; nodePointer; nodePointer = nodePointer->getNext()) {
			if (newNode->getElem() >= nodePointer->getElem())
				previousNode = nodePointer;
			else
				break;
		}

		if (nodePointer == head) {
			newNode->setNext(head);
			head = newNode;
		}
		else {
			newNode->setNext(nodePointer);
			if (previousNode == tail)
				tail = newNode;
			previousNode->setNext(newNode);
		}

	}
	size++;
	std::cout << "Inserted the element " << element << " into the Linked List:\n";
}

template <typename T>
void LinkedList<T>::remove(const T element) {
	Node<T> *newNode = new Node<T>(element);
	if (!head)
		std::cout << "There are no elements in the list\n";
	else {
		Node<T> *previousNode = nullptr;
		Node<T> *nodePointer;
		for (nodePointer = head; nodePointer; nodePointer = nodePointer->getNext()) {
			if (newNode->getElem() == nodePointer->getElem())
				break;
			else
				previousNode = nodePointer;
		}

		if (!nodePointer)
			std::cout << "The element does not exist in the list\n";
		else {
			if (nodePointer == head)
				head = head->getNext();
			else
				previousNode->setNext(nodePointer->getNext());
			if (nodePointer == tail)
				tail = previousNode;
			delete nodePointer;
			size--;
			std::cout << "Removed the element " << element << " from the Linked List:\n";
		}
	}
}

template <typename T>
void LinkedList<T>::print() {
	Node<T> *nodePointer = head;
	for (int i = 0; i < size; i++) {
		std::cout << nodePointer->getElem() << " ";
		nodePointer = nodePointer->getNext();
	}
	/*while (nodePointer) {
		std::cout << nodePointer->getElem() << " ";
		nodePointer = nodePointer->getNext();
	}*/
	std::cout << "\n";
}

template <typename T>
void LinkedList<T>::printNodesRecursively(Node<T> *node) {
	if (node) {
		std::cout << node->getElem() << " ";
		printNodesRecursively(node->getNext());
	}
}

template <typename T>
void LinkedList<T>::printRecursive() {
	printNodesRecursively(head);
}

template <typename T>
void LinkedList<T>::poptHead() {
	if (head) remove(head->getElem());
}

template <typename T>
void LinkedList<T>::popTail() {
	if (tail) remove(tail->getElem());
}

#endif