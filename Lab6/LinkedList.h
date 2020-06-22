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

	// Funciones
	Iterator insert(Iterator position, const T &element) {
		Node<T> *newNode = new Node<T>(element);
		newNode->setNext(position.nodePointer);
		if (position.nodePointer == nullptr) {
			if (tail) tail->setNext(newNode);
			tail = newNode;
		}
		if (position.nodePointer == head)
			head = newNode;
		position.nodePointer = newNode;
		this->size++;
		return position;
	}
	Iterator erase(Iterator position) {
		Node<T> *deleteNode = position.nodePointer;
		if (deleteNode == nullptr)
			pop_back();
		else {
			if (position.nodePointer) position.nodePointer = position.nodePointer->getNext();
			if (deleteNode == head) head = head->getNext();
			if (deleteNode == tail) tail = position.nodePointer;
			delete deleteNode;
			this->size--;
		}
		return position;
	}

	void print();
	void printRecursive();

	Iterator begin() const { return Iterator(head); }
	Iterator end() const { return nullptr; }

	T front() const;
	T back() const;

	bool empty() const;
	int _size() const;

	void pop_front();
	void pop_back();

	void clear();
};

// -- CONSTRUCTORES/DESTRUCTOR --
template <typename T>
LinkedList<T>::LinkedList() {
	this->size = 0;
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
bool LinkedList<T>::empty() const {
	return this->size == 0;
}

template <typename T>
int LinkedList<T>::_size() const {
	return this->size;
}

template <typename T>
T LinkedList<T>::front() const {
	return head->getElem();
}

template <typename T>
T LinkedList<T>::back() const {
	return tail->getElem();
}

template <typename T>
void LinkedList<T>::pop_front() {
	if (head) erase(head);
}

template <typename T>
void LinkedList<T>::pop_back() {
	if (tail) {
		if (size == 1) { delete tail; head = nullptr; tail = nullptr; }
		else {
			Node<T>* nodePointer = head;
			while (nodePointer->getNext()->getNext())
				nodePointer = nodePointer->getNext();
			this->tail = nodePointer;
			delete tail->getNext();
			tail->setNext(nullptr);
		}
		this->size--;
	}
}

template <typename T>
void LinkedList<T>::clear() {
	while (size)
		pop_front();
}

template <typename T>
void LinkedList<T>::print() {
	Node<T> *nodePointer = head;
	for (int i = 0; i < this->size; i++) {
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

#endif

/*void LinkedList<T>::insert(const T element) {
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
}*/

/*template <typename T>
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
			this->size--;
			std::cout << "Removed the element " << element << " from the Linked List:\n";
		}
	}
}*/