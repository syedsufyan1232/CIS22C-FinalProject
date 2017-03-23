// Syed Tihami 
//Stack.h
//  

#ifndef Stack_h
#define Stack_h

#include "LinkedList.h"

using namespace std;

template <class D>
class Stack : protected LinkedList<D> {
private:
	//    Stack();
	//    ~Stack();
	//    Stack(Stack & obj);
public:
	void push(D data) { LinkedList<D>::insertHead(data); }
	D pop() { return LinkedList<D>::removeHead(); }
	D top() { return LinkedList<D>::returnHead(); }
	bool isEmpty() { return LinkedList<D>::isEmpty(); }
	int getSize() { return LinkedList<D>::getCount(); }

};

#endif /* Stack_h */
