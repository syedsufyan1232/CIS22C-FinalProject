//	Syed Tihami
//  LinkedList.h
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>

using namespace std;


//***************************************************************************
//***************************************************************************
//                    Definition of Linked List:
//***************************************************************************
//***************************************************************************

//***************************************************************************
//Declaration of LinkedList template class                                  *
//***************************************************************************
template <class D>
class LinkedList {
private:

	struct llNode {
		D data;
		llNode* next;
		llNode() : next(nullptr) {}
	};

	llNode* head;
	llNode* rear;
	int count;
	template <class C>
	llNode* find(C data);
public:
	//Stack/Queue functions:
	void insertRear(D data);
	void insertHead(D data);
	D removeHead();
	D returnHead();
	D returnRear();

	//Linked List functions:
	LinkedList() { head = rear = nullptr; count = 0; }
	~LinkedList() { emptyList(); }
	LinkedList(const LinkedList& obj);
	const LinkedList &operator=(const LinkedList<D> &obj);

	void insertSorted(D data);
	template <class C>
	bool removeValue(C data);
	template <class C>
	D *search(C data);  //Note: Specialized function

	//Other functions:
	int getCount() { return count; }
	bool isEmpty() { return head == nullptr; }
	void emptyList() { while (!isEmpty()) removeHead(); }

	//Specialized Traversals:
	void printFile(ostream &out = std::cout);
	void printTable(ostream &out = std::cout);
};







//***************************************************************************
//***************************************************************************
//                   Implementation of Linked List:
//***************************************************************************
//***************************************************************************

//***************************************************************************
//Definition of LinkedList Template class copy constructor                  *
//***************************************************************************
template <class D>
LinkedList<D>::LinkedList(const LinkedList& obj) {
	head = rear = nullptr;
	count = 0;
	for (llNode* current = obj.head; current != nullptr; current = current->next) {
		insertRear(current->data);
		rear->next = nullptr;
	}
}

//***************************************************************************
//Definition of LinkedList Template class assignment operator overload      *
//***************************************************************************
template <class D>
const LinkedList<D> &LinkedList<D>::operator=(const LinkedList<D> &obj) {
	head = rear = nullptr;
	count = 0;
	for (llNode* current = obj.head; current != nullptr; current = current->next) {
		insertRear(current->data);
	}
	return *this;
}

//*************************************************************************************
//Definition of search function of LinkedList template class                          *
//This fuction accepts data as an argument and returns the address where it is found  *
//or nullptr if not found                                                             *
//*************************************************************************************
template <class D>
template <class C>
D *LinkedList<D>::search(C data) {
	llNode* search = nullptr;
	D temp;
	if (isEmpty()) {
		search = nullptr;
	}
	else if (head->data == data) {
		search = head;
	}
	else if ((search = find(data))) {
		search = search->next;
	}
	else {
		search = nullptr;
	}
	return search ? &search->data : nullptr;
}

//********************************************************************************
//Definition of find function of LinkedList template class                       *
//This fuction accepts data as an argument and returns the address BEFORE where  *
//it is found or nullptr if not found                                            *
//Note: This function is only to be used after the head case                     *
//and empty head case is checked. Otherwise, it will not work as expected        *
//********************************************************************************
template <class D>
template <class C>
typename LinkedList<D>::llNode* LinkedList<D>::find(C data) {
	llNode* previous = nullptr;
	llNode* search = nullptr;
	for (search = head; search->next != nullptr && previous == nullptr; search = search->next) {
		if (search->next->data == data) {
			previous = search;
		}
	}
	return previous;
}

//*************************************************************************************
//Definition of insertSorted function of LinkedList template class                    *
//This fuction accepts data as an argument and inserts it in sorted order in the list *
//*************************************************************************************
template <class D>
void LinkedList<D>::insertSorted(D data) {
	bool Break = false;
	if (!head || head->data >= data) {
		insertHead(data);
	}
	else if (rear->data <= data) {
		insertRear(data);
	}
	else {
		for (llNode* previous = head; previous->next && !Break; previous = previous->next) {
			if (previous->next->data >= data) {
				llNode* newNode = new llNode;
				newNode->data = data;
				newNode->next = previous->next;
				previous->next = newNode;
				Break = true;
			}
		}
	}
}

//***********************************************************************************
//Definition of insertHead function of LinkedList template class                    *
//This fuction accepts data as and places it at the head of the list                *
//***********************************************************************************
template <class D>
void LinkedList<D>::insertHead(D data) {
	llNode* newNode = new llNode;
	newNode->data = data;
	newNode->next = head;

	head = newNode;
	if (!rear) { rear = newNode; }
	count++;
}

//***********************************************************************************
//Definition of insertRear function of LinkedList template class                    *
//This fuction accepts data as and places it in the rear of the list                *
//***********************************************************************************
template <class D>
void LinkedList<D>::insertRear(D data) {
	llNode* newNode = new llNode;
	newNode->next = nullptr;
	newNode->data = data;

	if (rear) rear->next = newNode;
	rear = newNode;
	if (!head) { head = newNode; }
	count++;
}

//*************************************************************************************************
//Definition of removeValue function of LinkedList template class                                 *
//This fuction accepts data as an argument and removes that element from the linked list          *
//Returns true if removed, returns false if not found                                             *
//*************************************************************************************************
template <class D>
template <class C>
bool LinkedList<D>::removeValue(C data) {
	bool success = false;
	llNode* pointer = nullptr;

	if (isEmpty()) {
		success = false;
	}
	else if (head->data == data) {
		removeHead();
		success = true;
	}
	else if ((pointer = find(data))) {
		if (pointer->next->next == nullptr) {
			delete pointer->next;
			pointer->next = nullptr;
			rear = pointer;
			success = true;
		}
		else {
			llNode* temp = pointer->next->next;
			delete pointer->next;
			pointer->next = temp;
			success = true;
		}
	}
	return success;
}

//**********************************************************************************
//Definition of removeHead function of LinkedList template class                   *
//This fuction removes and returns the data stored at the head of a list           *
//**********************************************************************************
template <class D>
D LinkedList<D>::removeHead() {
	if (!isEmpty()) {
		llNode temp = *head;
		delete head;
		head = temp.next;
		if (!head) { rear = nullptr; }
		count--;
		return temp.data;
	}
	else {
		throw "Cannot remove from empty list";
	}
}

//**********************************************************************************
//Definition of returnHead function of LinkedList template class                   *
//This fuction only returns the data stored at the head of a list                  *
//**********************************************************************************
template <class D>
D LinkedList<D>::returnHead() {
	if (!isEmpty()) return head->data;
	else return D();
}

//**********************************************************************************
//Definition of returnRear function of LinkedList template class                   *
//This fuction only returns the data stored at the rear of a list                  *
//**********************************************************************************
template <class D>
D LinkedList<D>::returnRear() {
	if (!isEmpty()) return rear->data;
	else return D();
}

//**********************************************************************************
//Definition of printFile function of LinkedList template class                   *
//This fuction prints outs a linked list in a line; used for the hash table        *
//**********************************************************************************
template <class D>
void LinkedList<D>::printFile(ostream &out) {
	for (llNode *current = head; current; current = current->next) {
		current->data.printToFile(out);
		out << endl;
	}
}
//Note: This is a specialized function

//**********************************************************************************
//Definition of printTable function of LinkedList template class                   *
//This fuction prints outs a linked list in a line; used for the hash table        *
//**********************************************************************************
template <class D>
void LinkedList<D>::printTable(ostream &out) {
	out << "{ ";
	for (llNode *current = head; current; current = current->next) {
		out << current->data << (current->next ? ", " : " ");
	}
	out << " }";
}

#endif /* LinkedList_h */
