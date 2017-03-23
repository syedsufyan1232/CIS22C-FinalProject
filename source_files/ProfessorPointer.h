//  Eric Chung
//  ProfessorPointer.h
//

#ifndef ProfessorPointer_h
#define ProfessorPointer_h

#include "Professor.h"

class ProfessorPointer {
private:
	Professor *pointer;
public:
	static char sortParam;
	ProfessorPointer() : pointer(nullptr) {}
	ProfessorPointer(const ProfessorPointer &obj);
	const ProfessorPointer &operator=(ProfessorPointer &obj) {
		pointer = obj.pointer;
		return *this;
	}

	Professor* getPointer() { return pointer; }
	void setPointer(Professor* p) { pointer = p; }
	bool operator >=(const ProfessorPointer &obj);
	bool operator <=(const ProfessorPointer &obj);
	bool operator >=(const string &obj);
	bool operator <=(const string &obj);
	bool operator ==(const ProfessorPointer &obj);
	bool operator >(const ProfessorPointer &obj);
	bool operator <(const ProfessorPointer &obj);
	bool operator ==(const string &obj);
	bool operator >(const string &obj);
	bool operator <(const string &obj);
	friend istream &operator >>(istream &in, const ProfessorPointer &obj);
	friend ostream &operator<<(ostream &out, const ProfessorPointer &obj);
	void printToFile(ostream &out = cout) { pointer->printToFile(out); }
	operator Professor*() { return pointer; }
	operator string();

};

#endif /* ProfessorPointer_h */
