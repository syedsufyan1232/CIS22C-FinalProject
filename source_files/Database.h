//Eric Chung
#ifndef Database_h
#define Database_h

#include <string>
#include "Professor.h"
#include "HashTable.h"
#include "BinaryTree.h"
#include "ProfessorPointer.h"

using namespace std;

class Database {
private:
	HashTable <ProfessorPointer> hashTable;
	BinaryTree <ProfessorPointer> binaryTree;
	string filepath;
	int numProfessors;

public:
	Database(string);
	~Database();
	void inputFromFile();
	void linkProfessor(Professor temp);
	bool deleteProfessor(string);

	void addProfessor(string fN, string lN, string field);
	void enterRating(Professor*, int, int, bool, string);
	ProfessorPointer *searchProfessor(string lastName);
	bool removeProfessor(string lastName);
	void printBSTIndented(string);
	void displayInorder();
	void displayHashSequence();
	hashStatistics getStats() { return hashTable.setStatistics(); }
	void printField(string, string, int, ostream&);

};

#endif /* Database_h */
