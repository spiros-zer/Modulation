// (c) Spyridon Zervos


#include "BPSK.h"
#include "Bitstreams/Bitstream.h"
#include <cmath>
#include <array>
#include <iostream>

ComplexNumber* BPSK::GetModulationSymbols()
{
	return ModulationSymbols;
}

void BPSK::PrintModulationSymbols()
{
	std::cout << "Modulation Symbols of " << Name << std::endl;
	for (const ComplexNumbers& Symbol : ModulationSymbols)
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
	
	for (const uint8_t& Byte : InBitstream->GetBitstream())
	{
		std::cout << "Byte: " << std::hex << static_cast<int>(Byte) << "\n";
		for (int i = 7; i >= 0; --i)
		{
			int bit = (Byte >> i) & 1;
			std::cout << "bit: " << bit << " to Symbol: " << ModulationSymbols[bit].ToString() << std::endl;
			OutSymbolStream.emplace_back(ModulationSymbols[bit]);
		}
	}
}

void BPSK::ConvertToBinary(const std::vector<ComplexNumber>& OutSymbolstream, Bitstream& OutBitstream)
{
	for (ComplexNumber Complex : OutSymbolstream)
	{
		if (Complex == ModulationSymbols[0])
		{
			
		}
	}
}

BPSK::BPSK()
{
	M = 2;
	SpectralEfficiency = log2(M);
	Name = "BPSK";
}
