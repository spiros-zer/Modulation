// (c) Spyridon Zervos


#include "BPSK.h"
#include <iostream>

int main(int argc, char** argv)
{
	BPSK BPSKModulation;
	std::cout << BPSKModulation.GetSpectralEfficiency() << std::endl;

	std::cout << BPSKModulation.GetModulationSymbols()[0].ToString();
	return 0;
}