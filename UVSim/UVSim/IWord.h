#ifndef UVSIM_IWORD
#define UVSIM_IWORD

#include <iostream>

class IWord {
public:
	virtual std::string asInstruction() = 0;
	virtual int asInteger() = 0;
	virtual std::string getOpCode() = 0;
protected:
	char rawWord[5];
};

#endif