#include "nBitAdder.h"
#include <bitset>

nBitAdder* nBitAdder::nbaInstance;

nBitAdder::nBitAdder()
{
}

nBitAdder::~nBitAdder()
{
	delete nbaInstance;
}

nBitAdder* nBitAdder::getInstance()
{
	if (nBitAdder::nbaInstance == NULL)
	{
		nBitAdder::nbaInstance = new nBitAdder();
		return nBitAdder::nbaInstance;
	}
	return nBitAdder::nbaInstance;
}

nBitAdder::bit nBitAdder::HalfAdder(bit a, bit b)
{
	carry = a & b;
	return a ^ b;
}

nBitAdder::bit nBitAdder::FullAdder(bit a, bit b)
{
	bit sum = carry ^ (a ^ b);
	if (carry & (a ^ b))
		carry = 1;
	else if (carry & (a & b))
		carry = 1;
	else
		carry = 0;
	return sum;
}

int nBitAdder::nBitAdd(int a, int b)
{
	const int size = sizeof(int)*8;
	std::bitset<size> first(a);
	std::bitset<size> second(b);
	std::bitset<size> ans(0);
	ans[0] = HalfAdder(first[0], second[0]);
	int i = 0;
	for (i = 1; i < size; ++i)
	{
		ans[i] = FullAdder(first[i], second[i]);
	}
	return static_cast<int>(ans.to_ulong());
}
