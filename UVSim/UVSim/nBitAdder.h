#pragma once
static class nBitAdder
{
	typedef unsigned char bit;
	bit carry = 0;
public:
	nBitAdder();
	bit HalfAdder(bit a, bit b);
	bit FullAdder(bit a, bit b);
	int nBitAdd(int a, int b);
};

