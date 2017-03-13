#define _CRT_SECURE_NO_WARNINGS
#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
private:
	int month;
	int day;
	int year;

public:
	Date();
	Date(string);
	Date(int, int, int);
	virtual ~Date();
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	void setMonth(int);
	void setDay(int);
	void setYear(int);
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator==(const Date& d);
	friend ostream& operator<<(ostream& o, const Date& d);
	friend istream& operator>>(istream& i, Date& d);
};

#endif // DATE_H
