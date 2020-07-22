#include <iostream>
#include "ALU.h"

int main(int argc, char* args[]) {
	std::cout << ALU::Add(2, 2) << std::endl;
	std::cout << ALU::Subtract(2, 12) << std::endl;
	std::cout << ALU::Multiply(2, 2) << std::endl;
	std::cout << ALU::Divide(20, 2) << std::endl;
}