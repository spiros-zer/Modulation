// (c) Spyridon Zervos


#include "BPSK.h"
#include <iostream>
#include "Bitstream.h"
#include <array>

template<std::size_t N, class T>
constexpr std::size_t countof(T(&)[N]) { return N; }

int main(int argc, char** argv)
{
	BPSK BPSKModulation;
	std::cout << "> Modulation scheme (BPSK) Initialized" << std::endl;
	std::cout << BPSKModulation.GetSpectralEfficiency() << std::endl;
	BPSKModulation.PrintModulationSymbols();

	double Data[] = {-1, 0, 0.5, 1, 2, 3, 4, 5, 6, 7, 10, 1024};
	Bitstream Bytes{Data};
	Bytes.PrintBinary();

	//ComplexNumber Symbols[countof(Data) * sizeof(double)];
	std::vector<ComplexNumber> Symbols;

	BPSKModulation.ConvertToSymbols(&Bytes, Symbols);
	for (const ComplexNumber& Symbol : Symbols)
	{
		std::cout << Symbol.ToString() << " ";
	}
	std::cout << std::endl;

	return 0;
}
