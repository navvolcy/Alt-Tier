#include "GUI.h"
#include <iostream>
using namespace std;

GUI::GUI(Memory* drive, ALU* calc) {

	this->drive = drive;
	this->calc = calc;


}

void GUI::launch() {
// once everythig is loaded then launch will run the program 

	int counter = 0;
	bool more = true;
	cout << "\t\t\t\t***Welcome to UVSim!***" << endl << endl;
	cout << "This simulator will assist you in learning machine languageand computer architecture!" << endl;
	cout << "This machine uses a simple machine langauge called Basic Machine Language, or BasicML for short" << endl;
	cout << "Please enter your program instruction by inputting your desired command then pressing enter.";
	cout << endl << endl;
	cout << "Possible Commands: " << endl;
	cout << "READ - 10 \t    \'+1015\'" << endl;
	cout << "WRITE - 11 \t    \'+1127\'" << endl;
	cout << "LOAD - 20 \t    \'+2061\'" << endl;
	cout << "STORE - 21 \t    \'+2105\'" << endl;
	cout << "ADD - 30 \t    \'+3015\'" << endl;
	cout << "SUBTRACT - 31 \t    \'+3115\'" << endl;
	cout << "DIVIDE - 32 \t    \'+3299\'" << endl;
	cout << "MULTIPLY - 33 \t    \'+3324\'" << endl;
	cout << "BRANCH - 40 \t    \'+4084\'" << endl;
	cout << "BRANCHNEG - 41\t    \'+4164\'" << endl;
	cout << "BRANCHZERO - 42\t    \'+4290\'" << endl;
	cout << "HALT - 43 \t    \'+4376\'" << endl;
	cout << endl;
	cout << "Once you have entered the desired commands, enter \"end\" to begin processing." << endl;


	string user_input;
	while (more) {
		cin >> user_input;
		if (user_input == "end") {
			more = false;
			cout << endl;
		}
		else {
			// TODO: Validate user input here, Make sure input is correct.
			Word language = Word(user_input.at(0), user_input.at(1), user_input.at(2), user_input.at(3), user_input.at(4));
			drive->write(language, counter);
			counter++;

		}

	}

}