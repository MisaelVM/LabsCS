#include "LinkedList.h"

// -- CONSTRUCTORES/DESTRUCTOR --
LinkedList::LinkedList() {
	size = 0;
	head = nullptr;
}

LinkedList::LinkedList(LinkedList &o) {
	this->size = o.size;
	this->head = o.head;
}

LinkedList::LinkedList(int size, Node *head) {
	this->size = size;
	this->head = new Node(*head);
}

LinkedList::~LinkedList() {
	Node *nodePointer = head;
	while (nodePointer) {
		Node *nextNode = nodePointer->getNext();
		delete nodePointer;
		nodePointer = nextNode;
	}

	delete head;
}

// Funciones
void LinkedList::insert(const int element) {
	Node *newNode = new Node(element);
		if (!head) // Lista vacia
			head = newNode;
		else {
			Node *previousNode = nullptr;
			Node *nodePointer;
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
				previousNode->setNext(newNode);
			}
		}
	size++;
	std::cout << "Inserted the element " << element << " into the Linked List:\n";
}

void LinkedList::remove(const int element) {
	Node *newNode = new Node(element);
	if (!head)
		std::cout << "There are no elements in the list\n";
	else {
		Node *previousNode = nullptr;
		Node *nodePointer;
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
			delete nodePointer;
			size--;
			std::cout << "Removed the element " << element << " from the Linked List:\n";
		}
	}
}

void LinkedList::print() {
	Node *nodePointer = head;
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

void LinkedList::printNodesRecursively(Node* node) {
	if (node) {
		std::cout << node->getElem() << " ";
		printNodesRecursively(node->getNext());
	}
}

void LinkedList::printRecursive() {
	printNodesRecursively(head);
}