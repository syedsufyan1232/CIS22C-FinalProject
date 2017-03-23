//Eric Chung
#ifndef Professor_h
#define Professor_h

#include <string>
#include <iostream>
#include "LinkedList.h"
#include "Rating.h"

using namespace std;

class Professor {
private:
	string firstName;
	string lastName;
	string field;
	double avgScore;
	double avgDifficulty;
	double percentTakeAgain;
	LinkedList<Rating> ratingList;
	int numRatings;
	bool flag;
public:

	//Fundamental Functions:
	Professor() : avgDifficulty(0.0), avgScore(0.0), percentTakeAgain(0.0), numRatings(0), flag(false) {}
	Professor(const Professor &obj);
	~Professor() {}
	const Professor &operator=(const Professor &obj);

	void setProfessor(string, string, string);
	void setProfessor(string fName, string lName, string f, double s, double d, double a, LinkedList<Rating> list);
	void addRating(Rating temp);
	void removeRating(int index);
	void setFlag() { flag = true; }



	//Accessors:
	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }
	string getField() { return field; }
	double getDifficulty() { return avgDifficulty; }
	double getScore() { return avgScore; }
	bool getFlag() { return flag; }

	//Operator Overloads:
	bool operator>(const Professor obj) { return lastName > obj.lastName; }
	bool operator<(const Professor obj) { return lastName < obj.lastName; }
	bool operator==(const Professor obj) { return lastName == obj.lastName; }
	bool operator>=(const Professor obj) { return lastName > obj.lastName || lastName == obj.lastName; }
	bool operator<=(const Professor obj) { return lastName < obj.lastName || lastName == obj.lastName; }
	friend ostream &operator<<(ostream &out, const Professor &);
	friend istream &operator>>(istream &in, Professor &);
	void displayDetail(ostream &);
	void printToFile(ostream& out);
	friend class ProfessorPointer;
};

#endif /* Professor_h */
