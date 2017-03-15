#ifndef PROFESSOR_H_
#define PROFESSOR_H_

#include <iostream>
#include "Rating.h"
#include <string>
using namespace std;

class Professor
{
private:
	string field;
	string firstName;
	string lastName;
	double avgScore;
	double avgDiff;
	Rating rating;
public:

	Professor();
	~Professor();

	//accessors
	void setField(string f) { field = f; }
	void setfirstName(string fn) { firstName = fn; }
	void setlastName(string ln) { lastName = ln; }
	void setavgScore(double as) { avgScore = as;}
	void setavgDiff(double ad) { avgDiff = ad; }

	//mutators
	string getField() { return field; }
	string getfirstName() { return firstName; }
	string getlastName() { return lastName; }
	double getavgScore() { return avgScore; }
	double getavgDiff() { return avgDiff; }

	//behaviors
	string blockstring();
	string smallstring();
	bool operator< (const Professor& p);
	friend istream& operator>> (istream& i, Professor& p);
	friend ostream& operator<< (ostream& o, const Professor& p);

};
#endif