//Eric Chung
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Database.h"
#include "ProfessorPointer.h"
#include "Professor.h"
#include "BinaryTree.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

//Constructor and input functions:
Database::Database(string path) : filepath(path), numProfessors(0) {
	inputFromFile();
}

Database::~Database() {
	ofstream outputFile(filepath);
	hashTable.printFileInorder(outputFile);
	outputFile.close();

	binaryTree.deAllocate();
}

void Database::inputFromFile() {
	ifstream inputFile;
	inputFile.open(filepath);
	if (inputFile) {
		stringstream stream;
		while (!inputFile.eof()) {
			string line;
			getline(inputFile, line, '\n');
			if (line == "" && !inputFile.eof()) {
				Professor temp;
				stream >> temp;
				linkProfessor(temp);
				stream.clear();
			}
			else {
				stream << line + '\n';
			}
		}
	}
	else throw "ERROR: File could not be opened";
	inputFile.close();
}

void Database::linkProfessor(Professor temp) {
	ProfessorPointer pointer;
	Professor *link = new Professor;
	*link = temp;
	pointer.setPointer(link);

	hashTable.insert(pointer);
	binaryTree.insert(pointer);
	numProfessors++;
}

//Assumes that there are no duplicate last names
bool Database::deleteProfessor(string lN) {
	Professor *toDelete = searchProfessor(lN)->getPointer();
	binaryTree.remove(lN);
	hashTable.remove(lN);
	if (toDelete) {
		delete toDelete;
		numProfessors--;
		return true;
	}

	return false;
}

void Database::addProfessor(string fN, string lN, string field) {
	Professor temp;
	temp.setProfessor(fN, lN, field);
	linkProfessor(temp);
}

void Database::enterRating(Professor* data, int s, int diff, bool repeat, string comm) {
	Rating temp;
	//Find today's date
	Date today(3, 22, 2017);
	temp.setRating(s, diff, repeat, today, comm);
	data->addRating(temp);
}

ProfessorPointer *Database::searchProfessor(string lN) {
	ProfessorPointer *temp = hashTable.search(lN);
	return temp;
}

bool Database::removeProfessor(string lastName) {
	return deleteProfessor(lastName);
}

void Database::printBSTIndented(string path) {
	ofstream outputFile(path);
	binaryTree.printIndented(outputFile);
	outputFile.close();
}

void Database::displayInorder() {
	binaryTree.printInorder(cout);
}

void Database::displayHashSequence() {
	hashTable.displayHashOrder();
}

void Database::printField(string field, string sort, int order, ostream &out) {
	char tempSort = ProfessorPointer::sortParam;
	if (sort == "score")
		ProfessorPointer::sortParam = 's';
	else if (sort == "difficulty")
		ProfessorPointer::sortParam = 'd';
	else throw "ERROR: Invalid sort parameter";

	LinkedList<ProfessorPointer> printQueue;
	binaryTree.convertToList(printQueue);

	if (order == 0) {
		Professor *temp = nullptr;
		while (!printQueue.isEmpty()) {
			temp = printQueue.removeHead();
			if (temp && (temp->getField() == field)) {
				out << temp->getFirstName() << ' ' << temp->getLastName();
				out << "        " << showpoint << fixed << setprecision(1) << temp->getScore() << "        " << setprecision(1) << temp->getDifficulty() << endl;
				temp = nullptr;
			}
		}
	}
	else if (order == 1) {
		Stack<ProfessorPointer> stack;
		while (!printQueue.isEmpty()) {
			stack.push(printQueue.removeHead());
		}
		Professor *temp = nullptr;
		while (!stack.isEmpty()) {
			temp = stack.pop();
			if (temp && (temp->getField() == field)) {
				out << temp->getFirstName() << ' ' << temp->getLastName();
				out << "        " << showpoint << fixed << setprecision(1) << temp->getScore() << "        " << setprecision(1) << temp->getDifficulty() << endl;
				temp = nullptr;
			}
		}
	}
	ProfessorPointer::sortParam = tempSort;
}
