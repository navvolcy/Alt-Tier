#include "Memory.h"

Memory* Memory::memInst = NULL;

void Memory::write(Word word, int location) {
	// Writes word to location in memory. Includes bounds checking.
	if (location >= 100 || location < 0) {
		// Invalid Write
		throw new std::range_error("location out of bounds");
	}
	mem.at(location) = word;
}

Word Memory::read(int location) {
	// Reads word at location in memory. Includes bounds checking.
	if (location >= 100 || location < 0) {
		// Invalid Write
		throw new std::range_error("location out of bounds");
	}
	return mem.at(location);
}

std::vector<Word> Memory::DumpMemory() {
	return mem;
}

// Constructor - uses initializer list to set const variable
Memory::Memory(int memSize) : MEM_SIZE(memSize) {
	mem = std::vector<Word>(MEM_SIZE);
}

Memory* Memory::getInstance(int memSize) {
	if (!Memory::memInst == NULL) {
		Memory::memInst = new Memory(memSize);
		return Memory::memInst;
	}
	return Memory::memInst;
}

Memory::~Memory() {
	// Can be empty
}