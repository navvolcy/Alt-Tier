
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
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "Add 1 +" << i << ": " << alu->Add(1, i) << std::endl;
		std::cout << "Subtract 1000 -" << i << ": " << alu->Subtract(1000, i) << std::endl;
		std::cout << "Divide 1000 /" << i+1 << ": " << alu->Divide(1000, i + 1) << std::endl;
		std::cout << "Remainder 1000 %" << i+1 << ": " << alu->Remainder(1000, i + 1) << std::endl;
		std::cout << "Exponent 1 " << i << ": " << alu->Exponent(1, i) << std::endl;
		std::cout << "Multiply 2 *" << i << ": " << alu->Multiply(2, i) << std::endl;
	}
	cli->launch();
	// Begin Computing
	inter->run();
	inter->MemDump();
}