//Eric Chung
#ifndef _DATE_H
#define _DATE_H

#include <string>
#include <iostream>

using namespace std;

class Date {
private:
	int month;
	int day;
	int year;
public:
	Date(int m = 0, int d = 0, int y = 0) { setDate(m, d, y); }
	Date(string s);
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	void setDate(int, int, int);
	friend bool operator==(const Date &, const Date &);
	friend bool operator!=(const Date &, const Date &);
	friend bool operator>(const Date &, const Date &);
	friend bool operator<(const Date &, const Date &);
	friend bool operator>=(const Date &, const Date &);
	friend bool operator<=(const Date &, const Date &);
	friend ostream& operator<<(ostream& out, const Date &date);
	friend istream& operator>> (istream &, Date &);
};

#endif
