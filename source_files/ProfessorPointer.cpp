//Eric Chung

#include "ProfessorPointer.h"
#include <iostream>

using namespace std;

ProfessorPointer::ProfessorPointer(const ProfessorPointer &obj) {
	pointer = obj.pointer;
}

bool ProfessorPointer::operator ==(const ProfessorPointer &obj) {
	if (sortParam == 'f') return pointer->firstName == obj.pointer->firstName;
	else if (sortParam == 'l') return pointer->lastName == obj.pointer->lastName;
	else if (sortParam == 'd') return pointer->avgDifficulty == obj.pointer->avgDifficulty;
	else if (sortParam == 's') return pointer->avgScore == obj.pointer->avgScore;
	else throw "ERROR: Invalid search parameter for Professor Pointer";
}

bool ProfessorPointer::operator >(const ProfessorPointer &obj) {
	if (sortParam == 'f') return pointer->firstName > obj.pointer->firstName;
	else if (sortParam == 'd') return pointer->avgDifficulty > obj.pointer->avgDifficulty;
	else if (sortParam == 'l') return pointer->lastName > obj.pointer->lastName;
	else if (sortParam == 's') return pointer->avgScore > obj.pointer->avgScore;
	else throw "ERROR: Invalid search parameter for Professor Pointer";
}

bool ProfessorPointer::operator <(const ProfessorPointer &obj) {
	if (sortParam == 'f') return pointer->firstName < obj.pointer->firstName;
	else if (sortParam == 'l') return pointer->lastName < obj.pointer->lastName;
	else if (sortParam == 's') return pointer->avgScore < obj.pointer->avgScore;
	else if (sortParam == 'd') return pointer->avgDifficulty < obj.pointer->avgDifficulty;
	else throw "ERROR: Invalid sort parameter for Professor Pointer";
}

bool ProfessorPointer::operator ==(const string &obj) {
	if (sortParam == 'f') return pointer->firstName == obj;
	else if (sortParam == 'l') return pointer->lastName == obj;
	else throw "ERROR: Invalid sort parameter for Professor Pointer";
}

bool ProfessorPointer::operator >(const string &obj) {
	if (sortParam == 'f') return pointer->firstName > obj;
	else if (sortParam == 'l') return pointer->lastName > obj;
	else throw "ERROR: Invalid sort parameter for Professor Pointer";
}

bool ProfessorPointer::operator <(const string &obj) {
	if (sortParam == 'f') return pointer->firstName < obj;
	else if (sortParam == 'l') return pointer->lastName < obj;
	else throw "ERROR: Invalid sort parameter for Professor Pointer";
}

bool ProfessorPointer::operator >=(const ProfessorPointer &obj) {
	return (*this > obj || *this == obj);
}

bool ProfessorPointer::operator <=(const ProfessorPointer &obj) {
	return (*this < obj || *this == obj);
}

bool ProfessorPointer::operator >=(const string &obj) {
	return (*this > obj || *this == obj);
}

bool ProfessorPointer::operator <=(const string &obj) {
	return (*this < obj || *this == obj);
}

istream &operator >>(istream &in, const ProfessorPointer &obj) {
	in >> *obj.pointer;
	return in;
}

ostream &operator<<(ostream &out, const ProfessorPointer &obj) {
	out << *obj.pointer;
	return out;
}

ProfessorPointer::operator string() {
	if (sortParam == 'f') return pointer->firstName;
	else if (sortParam == 'l') return pointer->lastName;
	else throw "ERROR: Invalid sort parameter";
}
