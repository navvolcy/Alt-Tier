#pragma once
#include"Word.h"
#include"Memory.h"
#include "ICLI.h"
// include the interpreter Module.h

class CLI: public ICLI
{
private:
	CLI(Memory* drive);
	~CLI();
	Memory* drive;
	static CLI* cliInst;
public: 
	static CLI* getInstance(Memory* drive);
	void launch();

};
