#pragma once
#include"Word.h"
#include"Memory.h"
#include "ICLI.h"
// include the interpreter Module.h

class CLI: public ICLI
{
public: 
	CLI(Memory* drive);
	void launch();
private:
	Memory* drive;
};
