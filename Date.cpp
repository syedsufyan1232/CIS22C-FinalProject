#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::setDate(int m, int d, int y)
{
	day = d;
	month = m;
	year = y;
}

Date::Date(string s)
{
	string m, d, y;
	if (s.length() != 10)
		throw "Invalid Date Format";
	else
	{
		m = s.substr(0, 2);
		d = s.substr(3, 2);
		y = s.substr(6, 4);
		setDate(stoi(m), stoi(d), stoi(y));
	}

}

bool operator==(const Date &thi, const Date &tha)
{
	return thi.day == tha.day && thi.month == tha.month && thi.year == tha.year;
}

bool operator!=(const Date &thi, const Date &tha)
{
	return !operator==(tha,thi);
}

bool operator>(const Date &thi, const Date &tha)
{
	if (thi.year != tha.year)
		return thi.year > tha.year;
	else if (thi.month != tha.month)
		return thi.month > tha.month;
	else if (thi.day != tha.day)
		return thi.day > tha.day;
	return false;
}
bool operator<(const Date &thi, const Date &tha)
{
	return !operator>(thi, tha) && thi != tha;
}
bool operator>=(const Date &thi, const Date &tha)
{
	return operator==(thi, tha) || operator>(thi, tha);
}
bool operator<=(const Date &thi, const Date &tha)
{
	return operator==(thi, tha) || operator<(thi, tha);
}

ostream& operator<<(ostream& out, const Date &date)
//For printing the Date to standard output
{
    out << right <<setfill('0') << setw(2) << date.month << '/' << setfill('0') << setw(2) << date.day << '/' << date.year;
	return out;
}

istream &operator>>(istream &in, Date &date) {
    //For inputting the Date from the file to the inventory
    //also for entering the Date manually
    string input;
    in >> input;
    //For the sake of error handling:
    if (input.length() < 11) {
        input = "00/00/0000";
    }
    string tempMonth = input.substr(0, 2);
    string tempDay = input.substr(3, 2);
    string tempYear = input.substr(6, 4);
    date.month = stoi(tempMonth);
    date.day = stoi(tempDay);
    date.year = stoi(tempYear);
	return in;
}
