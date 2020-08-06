
#include "CLI.h"
#include "Memory.h"
#include "Interpreter.h"
#include "nBitAdder.h"
#include "ALU.h"

#include <iostream>

int main(int argc, char* args[]) {

	// This value controls the size of memory
	const int MEM_SIZE = 1000;

	// Prototype running order
	// Initialize modules
	Memory* mem = Memory::getInstance(MEM_SIZE);
	nBitAdder* nba = nBitAdder::getInstance();
	ALU* alu = ALU::getInstance(nba);
	CLI* cli = CLI::getInstance(mem);
	Interpreter* inter = Interpreter::getInstance(mem, alu);
	// Start CLI
	cli->launch();
	// Begin Computing
	inter->run();
	inter->MemDump();
}