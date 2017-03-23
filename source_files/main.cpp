// Bruce Wu
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Database.h"
#include "Professor.h"
#include <cctype>
#include <cstdlib>

using namespace std;

void userInterface(Database &data);
char ProfessorPointer::sortParam = 'l';

int main() {
	//Print name block
	cout << "--------------------------------------------------------------\n";
	cout << "\tTeam BEES: Command-line RateYourProfessor\n\n\tMembers:\n\tBruce Wu\n\tEric Chung\n\tEzra Sheng\n\tSyed Tihami\n\n\n";
	cout << "--------------------------------------------------------------\n";
	try {
		cout << "\tWelcome to RateYourProfessor!\n";
		cout << "--------------------------------------------------------------\n\n";
		//Create Database:
		string filepath;
		cout << "\tPlease enter the path for your input/output file:\n\t>>";
		getline(cin, filepath);
		cout << endl;
		Database database(filepath);

		//Perform User Interaction
		userInterface(database);
	}
	catch (const char* s) {
		cout << s << endl;
	}

	cin.get();
	return 0;
}

//Display options and communicate directly with Database
void userInterface(Database &data) {
	bool proceed = true;;
	string selection;
	do {
		cout << "--------------------------------------------------------------\n";
		cout << "\tPlease select from the following options:\n";
		cout << "--------------------------------------------------------------\n";
		cout << "\t1)Look up a professor\n\t2)Search for professors\n\t3)Add a professor\n\t4)Display Data - Hash Table Sequence\n\t5)Display Data - Sorted by last name\n\t6)Print indented tree to file\n\t7)Display efficiency statistics\n\t8)Quit\n";
		cout << "--------------------------------------------------------------\n";
		cout << "\tEnter a choice 1-8:\n\n\t>> ";
		cin >> selection;
		cin.ignore();
		cout << endl;
		switch (selection[0]) {
		case '1': {
			string search;
			ProfessorPointer *found = nullptr;

			cout << "\tPlease enter a name to search for:\n\t>>";
			getline(cin, search);
			found = data.searchProfessor(search);
			if (found) {
				string selection;
				cout << "\n\n\tProfessor Profile:\n";
				static_cast<Professor*>(*found)->displayDetail(cout);
				cout << "\tOptions:\n\t1)Rate this professor\n\t2)Delete professor\n\t3)Return to main menu\n\t>> ";
				getline(cin, selection);
				switch (selection[0]) {
				case '1': {
					if (static_cast<Professor*>(*found)->getFlag())
						cout << "\tSorry, but you can only enter one rating per professor!\n";
					else {
						int score, difficulty;
						char wouldTakeAgain;
						string comment;
						bool choice;
						cout << "\tPlease enter a score for Professor " << static_cast<Professor*>(*found)->getLastName() << ":\n\t>>";
						cin >> score;
						if (score > 5) score = 5;
						if (score < 1) score = 1;
						cout << "\tPlease rate the difficulty of Professor " << static_cast<Professor*>(*found)->getLastName() << ":\n\t>>";
						cin >> difficulty;
						if (difficulty > 5) difficulty = 5;
						if (difficulty < 1) difficulty = 1;
						cout << "\tWould you take Professor " << static_cast<Professor*>(*found)->getLastName() << "'s class again? (Y/N)\n\t>>";
						cin >> wouldTakeAgain;
						cin.ignore();
						if (!(toupper(wouldTakeAgain) == 'Y' || toupper(wouldTakeAgain) == 'N')) wouldTakeAgain = 1;
						else if (toupper(wouldTakeAgain == 'Y')) choice = true;
						else if (toupper(wouldTakeAgain == 'N')) choice = false;
						cout << "\tPlease give your input on Professor " << static_cast<Professor*>(*found)->getLastName() << ":\n\t>>";
						getline(cin, comment);
						cout << "\tSuccessfully added your rating to Professor " << static_cast<Professor*>(*found)->getLastName() << "'s profile.\n" << "\tThank you for your input!\n";
						static_cast<Professor*>(*found)->setFlag();
						data.enterRating(*found, score, difficulty, choice, comment);
					}

					break;
				}
				case '2': {
					if (data.removeProfessor(search)) {
						cout << "\tProfessor " << search << " was successfully removed from the database.\n";
					}
					else {
						throw "\tERROR: Could not delete professor";
					}
					break;
				}
				default: {
					break;
				}
				}
			}
			else
				cout << "\tSorry, that professor was not found!\n";
			break;
		}
		case '2': {
			string field;
			string selection;
			string sortBy;
			int order;
			cout << "\tPlease enter the department you would like to search in:\n\t>>";
			getline(cin, field);

			cout << "\n\tDisplay results in order of:\n\ta)Average Score\n\tb)Average Difficulty\n\t>> ";
			cin >> selection;
			cin.ignore();
			sortBy = (selection[0] == 'a' ? "score" : "difficulty");

			cout << "\n\tDisplay scores:\n\ta)Lowest scores first\n\tb)Highest scores first\n\t>> ";
			cin >> selection;
			cin.ignore();
			order = selection[0] == 'a' ? 0 : 1;
			cout << endl << field << "\t Department Results: \n";
			cout << setfill(' ');
			for (int i = 0; i < 35; i++) cout << '-';
			cout << endl << "Name:" << right << setw(20) << "Score:" << setw(15) << "Difficulty:" << endl;
			data.printField(field, sortBy, order, cout);
			for (int i = 0; i < 35; i++) cout << '-';
			break;
		}
		case '3': {
			string fName, lName, field;
			string total;
			cout << "\tPlease enter the first name of the professor you would like to add:\n\t>>";
			getline(cin, fName, '\n');
			cout << "\tPlease enter the last name of the professor you would like to add:\n\t>>";
			getline(cin, lName, '\n');
			cout << "\tPlease enter the field of the professor you would like to add:\n\t>>";
			getline(cin, field, '\n');
			data.addProfessor(fName, lName, field);
			cout << "\tAdded " << fName << ' ' << lName << " to database.\n";

			break;
		}
		case '4': {
			data.displayHashSequence();
			break;
		}
		case '5': {
			cout << "--------------------------------------------------------------\n";
			cout << "\tProfessors:\n";
			cout << "--------------------------------------------------------------\n";
			data.displayInorder();
			break;
		}
		case '6': {
			string outputFile;
			cout << "\tPlease enter the path to an output file:\n\t>> ";
			getline(cin, outputFile);
			data.printBSTIndented(outputFile);
			cout << "\tIndented tree printed to " << outputFile << endl;
			break;
		}
		case '7': {
			hashStatistics tempStat = data.getStats();
			cout << "--------------------------------------------------------------\n";
			cout << "\tEfficiency:\n";
			cout << "--------------------------------------------------------------\n";
			cout << "\tHash Table implementing list-based collision resolution\n\n";
			cout << "\tLongest Linked List: " << tempStat.longestList << " data entries.\n";
			cout << fixed << showpoint << setprecision(1) << "\tAverage List Length: " << tempStat.averageListSize << " data entries.\n";
			cout << fixed << showpoint << setprecision(2) << "\tLoad Factor: " << tempStat.loadFactor << endl;
			break;
		}
		case '8': {
			proceed = false;
			break;
		}
		default: {
			cout << "\tInvalid entry! Please try again:\n";
		}
		}
		cout << endl;
	} while (proceed);
	cout << "------------------------------------------------------------------------------------------\n";
	cout << "\tThank you for using RateYourProfessor and make sure to come back around!\n";
	cout << "------------------------------------------------------------------------------------------\n";
}
