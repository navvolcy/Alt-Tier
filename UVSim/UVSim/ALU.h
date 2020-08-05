#pragma once
#include "nBitAdder.h"

class ALU 
{
public:
    static int Add(int a, int b);
    static int Subtract(int minuend, int subtrahend);
    static int Multiply(int a, int b);
    static int Divide(int dividend, int divisor);
    static int Exponent(int base, int exponent);
    static int Remainder(int dividend, int divisor);
};

