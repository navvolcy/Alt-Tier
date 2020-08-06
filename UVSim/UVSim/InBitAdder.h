#ifndef UVSIM_INBITADDER
#define UVSIM_INBITADDER
class InBitAdder
{
public:
	typedef unsigned char bit;
	virtual bit HalfAdder(bit a, bit b) = 0;
	virtual bit FullAdder(bit a, bit b) = 0;
	virtual int nBitAdd(int a, int b) = 0;
protected:
	bit carry;
};

#endif