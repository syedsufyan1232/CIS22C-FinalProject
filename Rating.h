#ifndef RATING_H_
#define RATING_H_

#include <iostream>
#include "Date.h"
#include <sstream>
#include <string>
using namespace std;

class Rating
{
private:
	int score;
	string comment;
	Date date;
	int diff; 
public:
	Rating();
	Rating(int, int, string, Date);
	~Rating();

	//accessors
	void setScore(int);
	void setComment(string);
	void setDate(Date);
	void setDiff(int);

	//mutators
	int getScore() const;
	string getComment() const;
	Date getDate() const;
	int getDiff() const;

	//behaviors
	string blockstring();




};
#endif
