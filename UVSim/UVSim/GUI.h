#pragma once
#include"Word.h"
#include"ALU.h"
#include"Memory.h"
// include the interpreter Module.h

class GUI
{
public: 
	GUI(Memory* drive, ALU* calc);

	void launch();
private:

	Memory* drive;
	ALU* calc;

};
