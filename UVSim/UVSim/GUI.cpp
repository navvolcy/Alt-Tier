#include "GUI.h"
#include <iostream>

GUI::GUI(Memory* drive, ALU* calc) {

	this->drive = drive;
	this->calc = calc;


}

void GUI::launch() {
// once everythig is loaded then launch will run the program 

	int counter = 0;
	bool more = true;

	std::cout << "Welcome to UVSim, please enter your program instruction one at a time" << std::endl;
	std::string user_input;
	while (more) {
		std::cin >> user_input;
		if (user_input == "end") {
			more = false;
		}
		else {
			Word language = Word(user_input.at(0), user_input.at(1), user_input.at(2), user_input.at(3), user_input.at(4));
			drive->write(language, counter);
			counter++;

		}

	}

}