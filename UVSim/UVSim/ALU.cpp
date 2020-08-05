#include "ALU.h"
#include "nBitAdder.h"
#include <limits>
#include <iostream>

int ALU::Add(int a, int b)
{
    nBitAdder nba = nBitAdder();
    if (b == 0)
    {
        return a;
    }
    else
    {
        //int carry = a & b;
        //a = a ^ b;
       // carry <<= 1;
       // b = carry;
        return nba.nBitAdd(a, b);
    }
}

int ALU::Subtract(int minuend, int subtrahend)
{
    if (subtrahend == 0)
        return minuend;
    else
    {
        int borrow = (minuend ^ INT_MAX) & subtrahend;
        minuend = minuend ^ subtrahend;
        borrow <<= 1;
        subtrahend = borrow;
        return Subtract(minuend, subtrahend);
    }
}

int ALU::Multiply(int a, int b)
{
    if (b == 0)
        return 0;
    else if (b > 0)
        return (ALU::Add(a, Multiply(a, b - 1)));
    else
        return -Multiply(a, -b);
}

int ALU::Divide(int dividend, int divisor)
{
    if (divisor == 0)
        throw "ERR: Cannot divide by zero.";

    int sign = dividend < 0 || divisor < 0 ? -1 : 1;
    dividend = dividend < 0 ? dividend * -1 : dividend;
    divisor = divisor < 0 ? divisor * -1 : divisor;

    int quotient = 0;
    while (dividend >= divisor) {
        dividend = ALU::Subtract(dividend, divisor);
        quotient = ALU::Add(quotient,1);
    }

    return ALU::Multiply(sign, quotient);
}

int ALU::Exponent(int base, int exponent)
{
    if (exponent < 0)
        throw "ERR: Current implementation does not allow for negative exponent.";
    else if (exponent == 0)
        return 1;
    else
        return Multiply(base, Exponent(base, Subtract(exponent, 1)));
}

int ALU::Remainder(int dividend, int divisor)
{
    int sign = dividend >= 0 ? 1 : -1;
    dividend = dividend < 0 ? dividend * -1 : dividend;
    divisor = divisor < 0 ? divisor * -1 : divisor;
    int extra = dividend;
    while (extra > 0)
        extra = Subtract(extra, divisor);
    if (extra == 0)
        return 0;
    else
        return Multiply(Add(divisor, extra), sign);
}

