// (c) Spyridon Zervos


#include "BPSK.h"
#include "Bitstream.h"
#include <cmath>
#include <array>

ComplexNumber* BPSK::GetModulationSymbols()
{
	return ModulationSymbols;
}

void BPSK::PrintModulationSymbols()
{
	std::cout << "Modulation Symbols of " << Name << std::endl;
	for (const ComplexNumber& Symbol : ModulationSymbols)
	{
		std::cout << Symbol.ToString() << " ";
	}
	std::cout << std::endl;
}

void BPSK::ConstellationDiagram()
{

}

void BPSK::ConvertToSymbols(Bitstream* InBitstream, std::vector<ComplexNumber>& OutSymbolStream)
{
	
	for (const uint8_t& Bit : InBitstream->GetBitstream())
	{
		for (int i = 0; i < 7; ++i)
		{
			int bit = (Bit >> i) & 1;
			std::cout << "Bit: " << bit << "to Symbol: " << ModulationSymbols[bit].ToString() << std::endl;
			OutSymbolStream.emplace_back(ModulationSymbols[Bit]);
		}
	}
}

BPSK::BPSK()
{
	M = 2;
	SpectralEfficiency = log2(M);
	Name = "BPSK";
}
