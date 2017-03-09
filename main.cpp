//Main source file

#include <string>
#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Professor.h"

using namespace std;

int main() {
//Display Name block and Welcome Message

  //Get input file and set up:
  string filename;
  cout << "Please enter the name of the data file:\n";
  getline(cin, filename);
  LinkedList<Professor> professors = setup(filename);
  
  //User Interaction:
  controlMenu(professors);
  
  //End Porgram and Print Data:
  exit(filename, professors);
  return 0;
}

//***********************************************************************
//Definition of setup function
//This function takes a file path (string) as its argument and returns a sorted linked list of professor objects
//It inputs the data in the file (represented by the string) to the linked list
//***********************************************************************
LinkedList<Professor> setup(string path) {
  LinkedList<Professor> loadedList;
  ifstream input;
  input.open(path);
  //Read input, load onto the linked list
  input.close();
  return loadedList;
}

//***********************************************************************
//Definition of controlMenu function
//This function takes a sorted linked list of professor objects and returns nothing
//It acts as the primary user interface of the program
//***********************************************************************
void controlMenu(LinkedList<Professor> data) {

}

//***********************************************************************
//Definition of exit function
//This function takes the file path (string) and data (Linked List) as arguments and returns nothing
//It takes the sorted linked list and prints its contents to the input file
//***********************************************************************
void exit(string path, LinkedList<Professor> data) {
  ofstream output;
  output.open(path);
  //Print data onto file
  output.close();
}
