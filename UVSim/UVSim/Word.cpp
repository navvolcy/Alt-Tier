#include "Word.h"

std::string Word::asInstruction() {
	std::string s;
	for (int i = 1; i < 5; i++){
		s.push_back(rawWord[i]);
	}
	return s;
}

int Word::asInteger() {
	std::string s;
	for (int i = 0; i < 5; i++) {
		s.push_back(rawWord[i]);
	}
	return std::stoi(s);
}

std::string Word::getOpCode() {
	std::string s;
	s.push_back(rawWord[1]);
	s.push_back(rawWord[2]);
	return s;
}

// Constructor, created with individual chars
Word::Word(char sign, char c1, char c2, char c3, char c4) {
	rawWord[0] = sign;
	rawWord[1] = c1;
	rawWord[2] = c2;
	rawWord[3] = c3;
	rawWord[4] = c4;
}

// Constructor, created from an integer
Word::Word(int x) {
	if (x > 9999 || x < -9999) {
		std::string err = "Cannot store integer, Not enough space: " + std::to_string(x);
		throw std::runtime_error(err);
	}
	std::string a = std::to_string(x);
	if (x > 0) {
		if (x < 10) {
			rawWord[0] = '+';
			rawWord[1] = '0';
			rawWord[2] = '0';
			rawWord[3] = '0';
			rawWord[4] = a.at(0);
		}
		else if (x < 100) {
			rawWord[0] = '+';
			rawWord[1] = '0';
			rawWord[2] = '0';
			rawWord[3] = a.at(0);
			rawWord[4] = a.at(1);
		}
		else if (x < 1000) {
			rawWord[0] = '+';
			rawWord[1] = '0';
			rawWord[2] = a.at(0);
			rawWord[3] = a.at(1);
			rawWord[4] = a.at(2);
		}
		else {
			rawWord[0] = '+';
			rawWord[1] = a.at(0);
			rawWord[2] = a.at(1);
			rawWord[3] = a.at(2);
			rawWord[4] = a.at(3);
		}
	}
	else {
		if (x > -10) {
			rawWord[0] = a.at(0);
			rawWord[1] = '0';
			rawWord[2] = '0';
			rawWord[3] = '0';
			rawWord[4] = a.at(1);
		}
		else if (x > -100) {
			rawWord[0] = a.at(0);
			rawWord[1] = '0';
			rawWord[2] = '0';
			rawWord[3] = a.at(1);
			rawWord[4] = a.at(2);
		}
		else if (x > -1000) {
			rawWord[0] = a.at(0);
			rawWord[1] = '0';
			rawWord[2] = a.at(1);
			rawWord[3] = a.at(2);
			rawWord[4] = a.at(3);
		}
		else {
			rawWord[0] = a.at(0);
			rawWord[1] = a.at(1);
			rawWord[2] = a.at(2);
			rawWord[3] = a.at(3);
			rawWord[4] = a.at(4);
		}
	}
}