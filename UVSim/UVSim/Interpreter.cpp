#include "Interpreter.h"

Interpreter* Interpreter::intInst = NULL;

Interpreter::Interpreter(Memory* mem,ALU* alu) {
	// Register other modules
	this->mem = mem;
	this->alu = alu;
	// Initialize variables
	pc = 0;
	running = false; // Doesn't run until run() is called
	// set the accumulator to zero
	accumulator = Word('+', '0', '0', '0', '0');
}

Interpreter* Interpreter::getInstance(Memory* mem, ALU* alu) {
	if (Interpreter::intInst == NULL) {
		Interpreter::intInst = new Interpreter(mem, alu);
		return Interpreter::intInst;
	}
	return Interpreter::intInst;
}

Interpreter::~Interpreter()
{
	delete intInst;
}

void Interpreter::MemDump() {
	// Dumps out the current contents of memory
	std::cout << "REGISTERS: " << std::endl;
	std::cout << "Accumulator: " << "\t\t" << std::setfill('0') << std::setw(5) << accumulator.asInteger() << std::endl;
	std::cout << "InstructionCounter: " << "\t" << std::setfill('0') << std::setw(2) << pc << std::endl;
	std::cout << "InstructionRegister: " << "\t" << std::setfill('0') << std::setw(5) << ir.asInteger() << std::endl;
	std::cout << "Operation Code: " << "\t" << ir.getOpCode() << std::endl;
	std::cout << "Operand: " << "\t\t" << ir.asInstruction().substr(2, 4) << std::endl;
	std::cout << std::endl;
	std::cout << "MEMORY:" << std::endl;
	// Print Headers
	std::cout << "\t";
	int col = 0;
	for (int i = 0; i < 10; i++) {	
		std::cout << std::setfill('0') << std::setw(2) << col << "\t";
		col += 1;
	}
	std::cout << std::endl;
	int row = 0;
	std::vector<Word> memArr = mem->DumpMemory();
	for (int j = 0; j < 10; j++) {
		std::cout << std::setfill('0') << std::setw(2) << row << "\t";
		
		for (int k = 0; k < 10; k++) {
			if (memArr.at(row + k).asInteger() < 0) {
				std::cout << '1' << std::setfill('0') << std::setw(4) << std::abs(memArr.at(row + k).asInteger()) << "\t";
			}
			else
				std::cout << std::setfill('0') << std::setw(5) << memArr.at(row + k).asInteger() << "\t";
		}
		row += 10;
		std::cout << std::endl;
	}
}

void Interpreter::run() {
	std::string opCode;
	std::string operand;
	running = true;
	ir = mem->read(pc);
	while (running) {
		opCode = ir.getOpCode();
		operand = ir.asInstruction().substr(2, 4);
		switch (stoi(opCode)) {
		case 10:
			OpRead(stoi(operand));
			break;
		case 11:
			OpWrite(stoi(operand));
			break;
		case 20:
			OpLoad(stoi(operand));
			break;
		case 21:
			OpStore(stoi(operand));
			break;
		case 30:
			OpAdd(stoi(operand));
			break;
		case 31:
			OpSub(stoi(operand));
			break;
		case 32:
			OpDiv(stoi(operand));
			break;
		case 33:
			OpMul(stoi(operand));
			break;
		case 34:
			OpRemainder(stoi(operand));
			break;
		case 35:
			OpExponent(stoi(operand));
			break;
		case 40:
			OpBranch(stoi(operand));
			break;
		case 41:
			OpBranchNeg(stoi(operand));
			break;
		case 42:
			OpBranchZero(stoi(operand));
			break;
		case 43:
			OpHalt();
			break;
		default:
			std::string err = "Unknown instruction: " + ir.asInstruction();
			throw new std::runtime_error(err);
		}
		if (running) {
			// if not running will crash if trys to grab next word,
			// if there isn't a next word
			pc++;
			ir = mem->read(pc);
		}
	}
}

void Interpreter::OpRead(int memLoc) {
	// Read a word from the keyboard into a specific location in memory
	std::cout << "Enter an Integer: ";
	std::string uinput;
	std::cin >> uinput;
	// std::cout << std::endl;
	mem->write(Word(std::stoi(uinput)), memLoc);
}

void Interpreter::OpWrite(int memLoc) {
	// Write a word from a specific location in memory to the screen
	std::cout << "Contents of " << memLoc << " is ";
	std::cout << mem->read(memLoc).asInteger() << std::endl;
}

void Interpreter::OpLoad(int memLoc) {
	// Load a word from a specific location in memory into the accumulator
	accumulator = mem->read(memLoc);
}

void Interpreter::OpStore(int memLoc) {
	// Store a word from the accumulator into a specific location in Memory
	mem->write(accumulator, memLoc);
}

void Interpreter::OpAdd(int memLoc) {
	// Add a word from a specific location in memory to the word in the accumulator
	// (Leave the result in the accumulator)
	int a = mem->read(memLoc).asInteger();
	int b = accumulator.asInteger();
	int c = alu->Add(a, b);
	try {
		accumulator = Word(c);
	}
	catch (std::runtime_error e) {
		std::cout << std::endl << std::endl << e.what() << std::endl;
		std::cout << std::endl << "Terminating ..." << std::endl;
		exit(-1);
	}	
}

void Interpreter::OpSub(int memLoc) {
	// Subtract a word from a specific location in memory to the word in the accumulator
	int a = mem->read(memLoc).asInteger();
	int b = accumulator.asInteger();
	int c = alu->Subtract(b, a);
	try {
		accumulator = Word(c);
	}
	catch (std::runtime_error e) {
		std::cout << std::endl << std::endl << e.what() << std::endl;
		std::cout << std::endl << "Terminating ..." << std::endl;
		exit(-1);
	}
}

void Interpreter::OpDiv(int memLoc) {
	// Divide a word from a specific location in memory to the word in the accumulator
	int a = mem->read(memLoc).asInteger();
	int b = accumulator.asInteger();
	int c = alu->Divide(b, a);
	try {
		accumulator = Word(c);
	}
	catch (std::runtime_error e) {
		std::cout << std::endl << std::endl << e.what() << std::endl;
		std::cout << std::endl << "Terminating ..." << std::endl;
		exit(-1);
	}
}

void Interpreter::OpMul(int memLoc) {
	// Multiply a word from a specific location in memory to the word in the accumulator
	int a = mem->read(memLoc).asInteger();
	int b = accumulator.asInteger();
	int c = alu->Multiply(a, b);
	try {
		accumulator = Word(c);
	}
	catch (std::runtime_error e) {
		std::cout << std::endl << std::endl << e.what() << std::endl;
		std::cout << std::endl << "Terminating ..." << std::endl;
		exit(-1);
	}
}

void Interpreter::OpRemainder(int memLoc) {
	int a = mem->read(memLoc).asInteger();
	int b = accumulator.asInteger();
	int c = alu->Remainder(a, b);
	try {
		accumulator = Word(c);
	}
	catch (std::runtime_error e) {
		std::cout << std::endl << std::endl << e.what() << std::endl;
		std::cout << std::endl << "Terminating ..." << std::endl;
		exit(-1);
	}
}

void Interpreter::OpExponent(int memLoc) {
	int a = mem->read(memLoc).asInteger();
	int b = accumulator.asInteger();
	int c = alu->Exponent(a, b);
	try {
		accumulator = Word(c);
	}
	catch (std::runtime_error e) {
		std::cout << std::endl << std::endl << e.what() << std::endl;
		std::cout << std::endl << "Terminating ..." << std::endl;
		exit(-1);
	}
}

void Interpreter::OpBranch(int memLoc) {
	pc = memLoc - 1;
}

void Interpreter::OpBranchNeg(int memLoc) {
	int b = accumulator.asInteger();
	if (b < 0) {
		pc = memLoc - 1;
	}
}

void Interpreter::OpBranchZero(int memLoc) {
	int b = accumulator.asInteger();
	if (b == 0) {
		pc = memLoc - 1;
	}
}

void Interpreter::OpHalt() {
	std::cout << "*** UVSim execution terminated. ***" << std::endl;
	running = false;
}