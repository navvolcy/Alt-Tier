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

// Constructor
Word::Word(char sign, char c1, char c2, char c3, char c4) {
	rawWord[0] = sign;
	rawWord[1] = c1;
	rawWord[2] = c2;
	rawWord[3] = c3;
	rawWord[4] = c4;
}