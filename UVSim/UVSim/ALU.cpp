#include "ALU.h"
#include <limits>

int ALU::Add(int a, int b)
{
    if (b == 0)
        return a;
    else
    {
        int carry = a & b;
        a = a ^ b;
        carry <<= 1;
        b = carry;
        return Add(a, b);
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

