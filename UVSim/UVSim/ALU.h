#ifndef UVSIM_ALU
#define UVSIM_ALU
#include "IALU.h"
#include "nBitAdder.h"

class ALU : public IALU
{
private: 
    nBitAdder* nba;
    static ALU* aluInstance;
public:
    ALU(nBitAdder* nba);
    ~ALU();
    static ALU* getInstance(nBitAdder* nba);
    int Add(int a, int b);
    int Subtract(int minuend, int subtrahend);
    int Multiply(int a, int b);
    int Divide(int dividend, int divisor);
    int Exponent(int base, int exponent);
    int Remainder(int dividend, int divisor);
};

#endif