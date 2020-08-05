#ifndef UVSIM_IMEMORY
#define UVSIM_IMEMORY

#include <vector>
#include "Word.h"

class IMemory {
protected:
	std::vector<Word> mem;
public:
	virtual void write(Word word, int location) = 0;
	virtual Word read(int location) = 0;
	virtual std::vector<Word> DumpMemory() = 0;
};

#endif