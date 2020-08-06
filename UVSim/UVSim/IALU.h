#ifndef UVSIM_IALU
#define UVSIM_IALU
#include "nBitAdder.h"

class IALU
{
public:
    virtual int Add(int a, int b) = 0;
    virtual int Subtract(int minuend, int subtrahend) = 0;
    virtual int Multiply(int a, int b) = 0;
    virtual int Divide(int dividend, int divisor) = 0;
    virtual int Exponent(int base, int exponent) = 0;
    virtual int Remainder(int dividend, int divisor) = 0;
protected:
    nBitAdder* nba;
};

#endif