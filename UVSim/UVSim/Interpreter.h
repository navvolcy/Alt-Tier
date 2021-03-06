#ifndef UVSIM_INTERPRETER
#define UVSIM_INTERPRETER

#include "Word.h"
#include "Memory.h"
#include "ALU.h"

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cstdlib>

class Interpreter {
private:
	int pc;
	Word ir;
	Word accumulator;
	Memory* mem;
	ALU* alu;
	bool running;

	// Operations
	void OpRead(int memLoc);
	void OpWrite(int memLoc);
	void OpLoad(int memLoc);
	void OpStore(int memLoc);
	void OpAdd(int memLoc);
	void OpSub(int memLoc);
	void OpMul(int memLoc);
	void OpDiv(int memLoc);
	void OpBranch(int memLoc);
	void OpBranchNeg(int memLoc);
	void OpBranchZero(int memLoc);
	void OpHalt();
public:
	Interpreter(Memory* mem, ALU* alu);
	void run();
	void MemDump();
	/* Not sure how I want to implement these DEBUG functions
	void Break();
	void Continue();
	*/
};

#endif