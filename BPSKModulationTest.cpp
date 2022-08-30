// (c) Spyridon Zervos


#include "BPSKModulation.h"
#include <iostream>

int main(int argc, char** argv)
{
	BPSKModulation BPSK;
	std::cout << BPSK.GetSpectralEfficiency() << std::endl;
	return 0;
}