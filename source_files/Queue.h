//Syed Tihami  
//Queue.h
//  

#ifndef Queue_h
#define Queue_h

#include "LinkedList.h"

using namespace std;

template <class D>
class Queue : protected LinkedList<D> {
private:
	//    Queue();
	//    ~Queue();
	//    Queue(Queue & obj);
public:
	void enqueue(D data) { LinkedList<D>::insertRear(data); }
	D dequeue() { return LinkedList<D>::removeHead(); }
	D front() { return LinkedList<D>::returnHead(); }
	D rear() { return LinkedList<D>::returnRear(); }
	bool isEmpty() { return LinkedList<D>::isEmpty(); }
	int getSize() { return LinkedList<D>::getCount(); }

};

#endif /* Queue_h */
