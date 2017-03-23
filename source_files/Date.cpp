//Eric Chung

#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

void Date::setDate(int m, int d, int y) {
	day = d;
	month = m;
	year = y;
}

Date::Date(string str) {
	stringstream input;
	input << str;
	input >> *this;
}

bool operator==(const Date &left, const Date &right) {
	return left.day == right.day && left.month == right.month && left.year == right.year;
}

bool operator!=(const Date &left, const Date &right) {
	return !(left == right);
}

bool operator>(const Date &left, const Date &right) {
	if (left.year != right.year)
		return left.year > right.year;
	else if (left.month != right.month)
		return left.month > right.month;
	else if (left.day != right.day)
		return left.day > right.day;
	return false;
}

bool operator>=(const Date &left, const Date &right) {
	return left == right || left > right;
}

bool operator<(const Date &left, const Date &right) {
	return !(left >= right);
}

bool operator<=(const Date &left, const Date &right) {
	return !(left > right);
}

ostream& operator<<(ostream& out, const Date &date) {
	out << right << setfill('0') << setw(2) << date.month << '/' << setfill('0') << setw(2) << date.day << '/' << date.year;
	return out;
}

istream &operator>>(istream &in, Date &date) {
	int month, day, year;
	in >> month;
	in.ignore();
	in >> day;
	in.ignore();
	in >> year;
	date.setDate(month, day, year);
	return in;
}
