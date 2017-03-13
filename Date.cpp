#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Date::Date()
{
	/*
	Date::Date

	Default constructor - default date is 1/1/1900
	*/
	Date::month = 1;
	Date::day = 1;
	Date::year = 1900;
}

Date::Date(int m, int d, int y)
{/*
 Date::Date(int m, int d, int y)

 This constructor initializes the date as the parameters Month, Day, Year in that order
 Does not check for a valid month (1-12) or correct number of days in specific months
 */
	Date::month = m;
	Date::day = d;
	Date::year = y;
}

Date::Date(string mmddyyyy)
{
	/*
	Date::Date(string mmddyyyy)

	This constructor converts a string in Month/Day/Year format into a Date object
	*/
	stringstream ss(mmddyyyy);
	string m, d, y;
	getline(ss, m, '/');
	getline(ss, d, '/');
	getline(ss, y);
	Date::month = atoi(m.c_str());
	Date::day = atoi(d.c_str());
	Date::year = atoi(y.c_str());
}

Date::~Date()
{

	/*
	Date::~Date

	Default destructor
	*/
}

int Date::getMonth() const
{
	/*
	Date::getMonth

	Accessor for month member variable
	*/
	return Date::month;
}

int Date::getDay() const
{
	/*
	Date::getDay

	Accessor for day member variable
	*/
	return Date::day;
}

int Date::getYear() const
{
	/*
	Date::getYear

	Accessor for year member variable
	*/
	return Date::year;
}

void Date::setMonth(int m)
{
	/*
	Date::setMonth(int m)

	Allows user to set month to m
	*/
	Date::month = m;
}

void Date::setDay(int d)
{
	/*
	Date::setDay(int d)

	Allows user to set day to d
	*/
	Date::day = d;
}

void Date::setYear(int y)
{
	/*
	Date::setYear(int y)

	Allows user to set year to y
	*/
	Date::year = y;
}

bool Date::operator>(const Date& d)
{
	/*
	Date::operator<(const Date& d)

	Returns true if first date is earlier than second date
	*/
	if (Date::year > d.year)
		return true;
	else if (Date::year == d.year && Date::month > d.month)
		return true;
	else if (Date::year == d.year && Date::month == d.month && Date::day > d.day)
		return true;
	else return false;
}
bool Date::operator<(const Date& d)
{
	/*
	Date::operator<(const Date& d)

	Returns true if first date is earlier than second date
	*/
	if (Date::year < d.year)
		return true;
	else if (Date::year == d.year && Date::month < d.month)
		return true;
	else if (Date::year == d.year && Date::month == d.month && Date::day < d.day)
		return true;
	else return false;
}

bool Date::operator==(const Date& d)
{
	/*
	Date::operator==(const Date& d)

	Returns true if first date is same as second date
	*/

	if (Date::year == d.year && Date::month == d.month && Date::day == d.day)
		return true;
	else return false;
}

ostream& operator<<(std::ostream& o, const Date& d)
{
	/*
	ostream& operator<<(std::ostream& o, const Date& d)

	Allows a Date to be passed into an outstream as mm/dd/yyyy format
	*/
	o << setfill('0') << setw(2) << d.month << '/' << setw(2) << d.day << '/' << setw(4) << d.year;
	return o;
}

istream& operator>>(istream& i, Date& date)
{
	/*
	istream& operator>>(istream& i, Date& date)

	Reads a mm/dd/yyyy formatted Date from an input stream into a Date object
	*/
	string m, d, y;
	getline(i, m, '/');
	getline(i, d, '/');
	getline(i, y);
	date.month = atoi(m.c_str());
	date.day = atoi(d.c_str());
	date.year = atoi(y.c_str());
	return i;
}

