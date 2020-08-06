#include "ALU.h"
#include "nBitAdder.h"
#include <limits>
#include <iostream>

ALU* ALU::aluInstance;

ALU::ALU(nBitAdder* nba)
{
    this->nba = nba;
}

ALU::~ALU()
{
    delete aluInstance;
}

ALU* ALU::getInstance(nBitAdder* nba)
{
    if (ALU::aluInstance == NULL) 
    {
        ALU::aluInstance = new ALU(nba);
        return ALU::aluInstance;
    }
    return ALU::aluInstance;
}

int ALU::Add(int a, int b)
{
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
        return nba->nBitAdd(a, b);
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
        return ALU::aluInstance->Subtract(minuend, subtrahend);
    }
}

int ALU::Multiply(int a, int b)
{
    if (b == 0)
        return 0;
    else if (b > 0)
        return (ALU::aluInstance->Add(a, ALU::aluInstance->Multiply(a, b - 1)));
    else
        return -ALU::aluInstance->Multiply(a, -b);
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
        dividend = ALU::aluInstance->Subtract(dividend, divisor);
        quotient = ALU::aluInstance->Add(quotient,1);
    }

    return ALU::aluInstance->Multiply(sign, quotient);
}

int ALU::Exponent(int base, int exponent)
{
    if (exponent < 0)
        throw "ERR: Current implementation does not allow for negative exponent.";
    else if (exponent == 0)
        return 1;
    else
        return ALU::aluInstance->Multiply(base, ALU::aluInstance->Exponent(base, ALU::aluInstance->Subtract(exponent, 1)));
}

int ALU::Remainder(int dividend, int divisor)
{
    int sign = dividend >= 0 ? 1 : -1;
    dividend = dividend < 0 ? dividend * -1 : dividend;
    divisor = divisor < 0 ? divisor * -1 : divisor;
    int extra = dividend;
    while (extra > 0)
        extra = ALU::aluInstance->Subtract(extra, divisor);
    if (extra == 0)
        return 0;
    else
        return ALU::aluInstance->Multiply(ALU::aluInstance->Add(divisor, extra), sign);
}

