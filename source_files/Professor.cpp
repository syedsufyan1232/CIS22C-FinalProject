//Eric Chung
#include "Professor.h"
#include <sstream>
#include <iomanip>

Professor::Professor(const Professor &obj) {
	flag = obj.flag;
	firstName = obj.firstName;
	lastName = obj.lastName;
	field = obj.field;
	ratingList = obj.ratingList;
	numRatings = ratingList.getCount();
	avgScore = obj.avgScore;
	avgDifficulty = obj.avgDifficulty;
	percentTakeAgain = obj.percentTakeAgain;
}

const Professor &Professor::operator=(const Professor &obj) {
	flag = obj.flag;
	firstName = obj.firstName;
	lastName = obj.lastName;
	field = obj.field;
	ratingList = obj.ratingList;
	numRatings = ratingList.getCount();
	avgScore = obj.avgScore;
	avgDifficulty = obj.avgDifficulty;
	percentTakeAgain = obj.percentTakeAgain;

	return *this;
}

void Professor::setProfessor(string fName, string lName, string f) {
	firstName = fName;
	lastName = lName;
	field = f;
	numRatings = 0;
	avgDifficulty = avgScore = percentTakeAgain = 0.0;
}

void Professor::setProfessor(string fName, string lName, string f, double s, double d, double a, LinkedList<Rating> list) {
	firstName = fName;
	lastName = lName;
	field = f;
	avgScore = s;
	avgDifficulty = d;
	percentTakeAgain = a;
	ratingList = list;
	numRatings = ratingList.getCount();
}

void Professor::addRating(Rating temp) {
	int totalScore, totalDifficulty, totalRepeat;
	totalScore = avgScore * numRatings;
	totalDifficulty = avgDifficulty * numRatings;
	totalRepeat = percentTakeAgain * numRatings;
	totalScore += temp.getScore();
	totalDifficulty += temp.getDifficulty();
	totalRepeat += temp.getWouldTakeAgain() * 100;

	ratingList.insertRear(temp);
	numRatings++;

	avgScore = totalScore / numRatings;
	avgDifficulty = totalDifficulty / numRatings;
	percentTakeAgain = totalRepeat / numRatings;
}

void Professor::displayDetail(ostream &out) {
	out << '\t' <<firstName << ' ' << lastName << endl;
	out << "\t" << field << " \tDepartment\n\n";
	if (numRatings) {
		out << "\tAverage Rating: " << left << setprecision(1) << fixed << showpoint << avgScore << "   Average Difficulty: " << avgDifficulty << endl;
		out << "\t" << noshowpoint << setprecision(0) << percentTakeAgain << "% of students would take this professor again.\n\n";
		out << "\tRatings:\n\n";
		LinkedList<Rating> tempList = ratingList;
		while (!tempList.isEmpty())
			out << tempList.removeHead() << endl << endl;
	}
	else {
		out << "\tThis professor has not been rated yet.\n";
	}
	out << endl;
}

void Professor::printToFile(ostream& out) {
	out << firstName << '~' << lastName << '~' << field << endl;
	LinkedList<Rating> tempList;
	tempList = ratingList;
	for (int i = 0; i < numRatings; i++) {
		tempList.removeHead().printToFile(out);
		out << endl;
	}
}

ostream& operator<<(ostream& out, const Professor &prof) {
	out << prof.firstName << " " << prof.lastName;
	return out;
}

istream &operator>>(istream &in, Professor &prof) {
	string fN, lN, f;
	double avgScore = 0.0, avgDiff = 0.0, takeAgain = 0.0;
	int numRatings = 0, tempScore = 0, tempDiff = 0, tempRepeat = 0;
	LinkedList<Rating> ratings;
	Rating tempRate;

	getline(in, fN, '~');
	getline(in, lN, '~');
	getline(in, f, '\n');
	while (in >> tempRate) {
		tempScore += tempRate.getScore();
		tempDiff += tempRate.getDifficulty();
		tempRepeat += tempRate.getWouldTakeAgain();
		numRatings++;
		ratings.insertRear(tempRate);
	}

	if (numRatings) {
		avgScore = static_cast<double>(tempScore) / numRatings;
		avgDiff = static_cast<double>(tempDiff) / numRatings;
		takeAgain = (static_cast<double>(tempRepeat) / numRatings) * 100;
	}

	prof.setProfessor(fN, lN, f, avgScore, avgDiff, takeAgain, ratings);
	return in;
}
