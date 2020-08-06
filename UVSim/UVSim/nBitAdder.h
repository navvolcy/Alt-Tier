#ifndef UVSIM_NBITADDER
#define UVSIM_NBITADDER

#include "InBitAdder.h"
class nBitAdder: public InBitAdder
{
private:
	bit carry = 0;
	static nBitAdder* nbaInstance;
public:
	nBitAdder();
	~nBitAdder();
	static nBitAdder* getInstance();
	bit HalfAdder(bit a, bit b);
	bit FullAdder(bit a, bit b);
	int nBitAdd(int a, int b);
};

#endif