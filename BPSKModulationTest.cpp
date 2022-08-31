// (c) Spyridon Zervos


#include "BPSKModulation.h"
#include <iostream>
#include "ComplexNumbersLibrary.h"

int main(int argc, char** argv)
{
	BPSKModulation BPSK;
	std::cout << BPSK.GetSpectralEfficiency() << std::endl;
	return 0;
}