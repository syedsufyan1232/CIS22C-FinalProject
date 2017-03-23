//	Ezra Sheng
//  HashTable.h
//

#ifndef HashTable_h
#define HashTable_h

#include "LinkedList.h"

using namespace std;

struct hashStatistics {
	int longestList;
	double averageListSize;
	int elementsUsed;
	int arrayLength;
	double loadFactor;
	hashStatistics() { longestList = averageListSize = arrayLength = elementsUsed = 0.0; }
};

template <class D>
class HashTable {
private:
	LinkedList<D> *array;
	int arraySize;
	hashStatistics stats;
	int numElements;
	int hash(string);
public:
	HashTable();
	HashTable(int size);
	~HashTable();
	HashTable(const HashTable &);
	const HashTable &operator=(const HashTable &);

	void insert(D);
	bool remove(string);
	D* search(string);  //Note: Specialized function
	void printFileInorder(ostream &out = cout);
	void displayHashOrder(ostream &out = cout);
	hashStatistics setStatistics();

};







template <class D>
HashTable<D>::HashTable()  {
	arraySize = 37;
	array = new LinkedList<D>[arraySize];
	numElements = 0;
}

template <class D>
HashTable<D>::HashTable(int size) {
	arraySize = size;
	array = new LinkedList<D>[arraySize];
	numElements = 0;
}

template <class D>
HashTable<D>::~HashTable() {
	delete[] array;
	numElements = 0;
}

template <class D>
HashTable<D>::HashTable(const HashTable<D> &obj) {
	//stats.arraySize = arraySize = obj.arraySize;
	array = new LinkedList<D>[arraySize];
	*array = *obj.array;
	stats = obj.stats;
	numElements = obj.numElements;
}

template <class D>
const HashTable<D> &HashTable<D>::operator=(const HashTable<D> &obj) {
	//stats.arraySize = arraySize = obj.arraySize;
	array = new LinkedList<D>[arraySize];
	*array = *obj.array;
	stats = obj.stats;
	numElements = obj.numElements;
	return *this;
}

template <class D>
int HashTable<D>::hash(string key) {
	int value = 0;
	for (int i = 0; i < key.length(); i++)
		value += key[i];
	return (value * key.length()) % arraySize;
}

template <class D>
void HashTable<D>::insert(D value) {
	int index = hash(value);
	array[index].insertSorted(value);
	numElements++;
}

template <class D>
bool HashTable<D>::remove(string value) {
	int index = hash(value);
	if (array[index].removeValue(value)) {
		numElements--;
		return true;
	}
	return false;
}

template <class D>
D* HashTable<D>::search(string value) {
	int index = hash(value);
	D* location = array[index].search(value) ? array[index].search(value) : nullptr;
	return location;
}

template <class D>
void HashTable<D>::printFileInorder(ostream &out) {
	for (int i = 0; i < arraySize; i++) {
		array[i].printFile(out);
	}
}

template <class D>
void HashTable<D>::displayHashOrder(ostream &out) {
	out << "--------------------------------------------------------------\n";
	for (int i = 0; i < arraySize; i++) {
		out << "\t[" << setfill('0') << setw(2) << i << "] ";
		array[i].printTable(out);
		out << endl;
	}
}

template <class D>
hashStatistics HashTable<D>::setStatistics() {
	int maxArraySize = 0;
	int tempArraySize;
	int totalSize = 0;
	int usedElements = 0;
	for (int i = 0; i < arraySize; i++) {
		tempArraySize = array[i].getCount();
		totalSize += tempArraySize;
		if (tempArraySize > maxArraySize)
			maxArraySize = tempArraySize;
	}

	if (arraySize) {
		stats.averageListSize = static_cast<double>(totalSize) / arraySize;
		stats.loadFactor = static_cast<double>(totalSize) / arraySize;
	}
	stats.longestList = maxArraySize;
	stats.elementsUsed = usedElements;
	stats.arrayLength = arraySize;;
	return stats;
}


#endif /* HashTable_h */
