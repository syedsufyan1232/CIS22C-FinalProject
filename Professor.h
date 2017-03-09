#ifndef _Professor_H_
#def _Professor_H_

#include <string>

class Professor {
private:
Rating ratings;
double avScore;
double avDifficulty;

public:
Professor() {}
//Professor(a, b, c) {} For example
Professor(Professor &obj) {}
~Professor() {}

};

#endif
