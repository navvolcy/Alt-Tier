#ifndef UVSIM_MEMORY
#define UVSIM_MEMORY

#include "Word.h"
#include <vector>
#include <stdexcept>

class Memory {
private:
	
	// This is the raw memory
	std::vector<Word> mem;
public:
	const int MEM_SIZE;

	// Constructor - this sets up the memory vector
	Memory(int memSize);

	// Write word to location in memory. Includes bounds checking
	void write(Word word, int location);
	// read word from location in memory. Includes bounds checking
	Word read(int location);

	// Debug functions
	// returns the entire contents of memory
	std::vector<Word> DumpMemory();
};

#endif