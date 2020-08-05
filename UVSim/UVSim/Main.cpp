
#include "CLI.h"
#include "Memory.h"
#include "Interpreter.h"

#include <iostream>

int main(int argc, char* args[]) {

	// This value controls the size of memory
	const int MEM_SIZE = 1000;

	// Prototype running order
	// Initialize modules
	Memory* mem = Memory::getInstance(MEM_SIZE);
	CLI* cli = CLI::getInstance(mem);
	Interpreter* inter = Interpreter::getInstance(mem);
	// Start CLI
	cli->launch();
	// Begin Computing
	inter->run();
	inter->MemDump();

	delete cli;
	delete mem;
}