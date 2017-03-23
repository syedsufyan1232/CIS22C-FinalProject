//Eric Chung
#ifndef Rating_h
#define Rating_h

#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

class Rating {
private:
	int score;
	int difficulty;
	bool wouldTakeAgain;
	Date date;
	string comment;
public:
	Rating() { score = difficulty = 0; }
	void setRating(int s, int d, bool again, Date da, string comm);

	//Accessors:
	int getScore() { return score; }
	int getDifficulty() { return difficulty; }
	int getWouldTakeAgain() { return wouldTakeAgain; }
	Date getDate() { return date; }
	string getComent() { return comment; }

	//Operator Overloads:
	friend bool operator >(Rating left, Rating right);
	friend bool operator <(Rating left, Rating right);
	friend bool operator ==(Rating left, Rating right);
	friend bool operator <=(Rating left, Rating right);
	friend bool operator <=(Rating left, Rating right);

	friend ostream& operator<<(ostream& out, const Rating &rate);
	friend istream& operator>> (istream &, Rating &);
	void printToFile(ostream& out);
};

#endif /* Rating_h */
