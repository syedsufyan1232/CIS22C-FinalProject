#include "Rating.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

Rating::Rating()
{
	/*
	Default Constructor
	Default rating is 0.0 score, 0.0 difficulty, "comment" comment, and 1/1/1900 date
	*/
	Rating::score = 0.0;
	Rating::diff = 0.0;
	Rating::comment = "comment";
	Rating::date = Date(1, 1, 1900);
}

Rating::Rating(int s, int di, string c, Date d)
{
	/*
	This constructor initializes the rating as the parameters Score, Difficulty, Comment, and Date in that order
	*/
	Rating::score = s;
	Rating::diff = di;
	Rating::comment = c;
	Rating::date = d;
}

Rating::~Rating()
{
	//Default Destructor
}

int Rating::getScore() const
{
	return Rating::score;
}

int Rating::getDiff() const
{
	return Rating::diff;
}

string Rating::getComment() const
{
	return Rating::comment;
}

Date Rating::getDate() const
{
	return Rating::date;
}

void Rating::setScore(int s)
{
	Rating::score = s;
}

void Rating::setDiff(int di)
{
	Rating::diff = di;
}

void Rating::setComment(string c)
{
	Rating::comment = c;
}

void Rating::setDate(Date d)
{
	Rating::date = d;
}

string Rating::blockstring()
{
	stringstream ss;
	ss << "\t-----------------------------------------------------------------" << endl;
	ss << "\tDate: " << Rating::date << endl;
	ss << "\tScore: " << Rating::score << endl;
	ss << "\tDifficulty: " << Rating::diff << endl;
	ss << "\tComment: " << Rating::comment << endl;
	ss << "\t-----------------------------------------------------------------" << endl;
	return ss.str();
}