#ifndef UVSIM_WORD
#define UVSIM_WORD

#include <string>

class Word {
private:
	// Word will be stored as a char[] of size 5, Sign bit, plus 4 digits
	// Sign bit is significant for storing integers, does not affect instructions
	char rawWord[5];
public:
	// WIll return the word as an instruction, 4 digits, disregarding the sign bit
	std::string asInstruction();
	// Will return the word as a signed integer
	int asInteger();
	// returns the first two digits as a string OPCODE
	std::string getOpCode();
	// Constructors - this style forces bad input to be handled by class creating the words,
	// rather than the actual words themselves
	Word(char sign, char c1, char c2, char c3, char c4);
};

#endif