//Eric Chung
#include "Rating.h"
#include "Date.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void Rating::setRating(int s, int d, bool again, Date da, string comm) {
	score = s;
	difficulty = d;
	wouldTakeAgain = again;
	date = da;
	comment = comm;
}

void Rating::printToFile(ostream& out) {
	out << score << '~' << difficulty << '~' << wouldTakeAgain << '~' << date << '~' << comment;
}

ostream& operator<<(ostream& out, const Rating &rate) {
	out << "---------------------------------------------------------------------------\n" << rate.date << "     Score: " << rate.score << "     Difficulty: " << rate.difficulty << "     Would Take Again: " << (rate.wouldTakeAgain ? "Yes" : "No") << endl << endl << "Comment: " << rate.comment;
	return out;
}

istream &operator>>(istream &in, Rating &rate) {
	int score, difficulty, again;
	string comment;
	Date date;
	in >> score;
	in.ignore();
	in >> difficulty;
	in.ignore();
	in >> again;
	in.ignore();
	in >> date;
	in.ignore();
	getline(in, comment, '\n');
	rate.setRating(score, difficulty, again, date, comment);

	return in;
}
