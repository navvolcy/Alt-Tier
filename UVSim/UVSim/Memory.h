#ifndef UVSIM_MEMORY
#define UVSIM_MEMORY

#include "Word.h"
#include "IMemory.h"

#include <vector>
#include <stdexcept>

class Memory: public IMemory {
private:
	// Constructor - this sets up the memory vector
	Memory(int memSize);
	// This is the raw memory
	std::vector<Word> mem;
	static Memory* memInst;
public:
	const int MEM_SIZE;
	
	static Memory* getInstance(int memSize);
	// Write word to location in memory. Includes bounds checking
	void write(Word word, int location);
	// read word from location in memory. Includes bounds checking
	Word read(int location);

	// Debug functions
	// returns the entire contents of memory
	std::vector<Word> DumpMemory();
	~Memory();
};

#endif