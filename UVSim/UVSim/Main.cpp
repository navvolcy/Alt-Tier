
#include "GUI.h"
#include "ALU.h"
#include "Memory.h"
#include "Interpreter.h"

#include <iostream>

int main(int argc, char* args[]) {

	/* ALU FUNCTIONALITY TESTING
	std::cout << ALU::Add(2, 2) << std::endl;
	std::cout << ALU::Subtract(2, 12) << std::endl;
	std::cout << ALU::Multiply(2, 2) << std::endl;
	std::cout << ALU::Divide(20, 2) << std::endl;
	*/

	// This value controls the size of memory
	const int MEM_SIZE = 100;

	// Prototype running order
	// Initialize modules
	Memory* mem = new Memory(MEM_SIZE);
	ALU* alu = new ALU();
	GUI* gui = new GUI(mem, alu);
	Interpreter inter = Interpreter(mem, alu);
	// Start GUI
	gui->launch();
	// Begin Computing
	inter.run();
	inter.MemDump();
}