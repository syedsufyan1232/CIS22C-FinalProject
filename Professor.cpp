#include "Professor.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

Professor::Professor()
{
	/*Default constructor to set values for*/
	Professor::field = "field";
	Professor::firstName = "firstName";
	Professor::lastName = "lastName";
	Professor::avgScore = 0.0;
	Professor::avgDiff = 0.0;
	Professor::rating = Rating(0.0, 0.0, "comment", Date(1, 1, 1900));

}

Professor::~Professor()
{
	//destructor
}

string Professor::smallstring()
{
	/* Prints relevant Professor information*/
	stringstream ss;
	ss << "\t-----------------------------------------------------------------" << endl;
	ss << "\tProfessor Name: " << Professor::firstName << " " << Professor::lastName << endl;
	ss << "\tField: " << Professor::field << endl;
	ss << "\tAverage Score: " << fixed << setprecision(2) << Professor::avgScore << endl;
	ss << "\tAverage Difficulty: " << fixed << setprecision(2) << Professor::avgDiff << endl;
	ss << "\t-----------------------------------------------------------------" << endl;
	return ss.str();
}

string Professor::blockstring()
{
	/*Prints all Professor information*/
	stringstream ss;
	ss << "\t-----------------------------------------------------------------" << endl;
	ss << "\tProfessor Name: " << Professor::firstName << " " << Professor::lastName << endl;
	ss << "\tField: " << Professor::field << endl;
	ss << "\tAverage Score: " << fixed << setprecision(2) << Professor::avgScore << endl;
	ss << "\tAverage Difficulty: " << fixed << setprecision(2) << Professor::avgDiff << endl;
	ss << "\t-----------------------------------------------------------------" << endl;
	return ss.str();
}