#include "CLI.h"
#include <iostream>

CLI::CLI(Memory* drive) {
	this->drive = drive;
}

void CLI::launch() {
// once everythig is loaded then launch will run the program 

	int counter = 0;
	bool more = true;

	std::cout << "Welcome to UVSim, please enter your program instruction one at a time.";
	std::cout << "Enter \"end\" to begin processing." << std::endl;
	std::string user_input;
	while (more) {
		std::cin >> user_input;
		if (user_input == "end") {
			more = false;
		}
		else {
			// TODO: Validate user input here, Make sure input is correct.
			Word language = Word(user_input.at(0), user_input.at(1), user_input.at(2), user_input.at(3), user_input.at(4));
			drive->write(language, counter);
			counter++;

		}

	}

}