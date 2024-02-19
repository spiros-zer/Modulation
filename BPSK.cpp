// (c) Spyridon Zervos


#include "BPSK.h"
#include "Bitstreams/Bitstream.h"
#include <cmath>
#include <array>
#include <iostream>

// Initialize the static instance
BPSK BPSK::instance;

// Define the function to get the instance of the singleton
BPSK& BPSK::GetBPSKSystem() {
	return instance;
}

// Private constructor
BPSK::BPSK() {
	SetAlphabetSize(2);
	SetSpectralEfficiency(log2(GetAlphabetSize()));
	SetModulationName("BPSK");
}

// Private destructor
BPSK::~BPSK() {
	// Cleanup code, if any
}

// ComplexNumbers* BPSK::GetModulationSymbols()
// {
// 	return ModulationSymbols;
// }

void BPSK::PrintModulationSymbols()
{
	std::cout << "Modulation Symbols of " << GetModulationName() << '\n';
	for (const ComplexNumbers& Symbol : ModulationSymbols)
	{
		std::cout << Symbol.ToString() << " ";
	}
	std::cout << '\n';
}

void BPSK::ConstellationDiagram()
{

}

void BPSK::ConvertToSymbols(Bitstream* InBitstream, std::vector<ComplexNumbers>& OutSymbolStream)
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

void BPSK::ConvertToBinary(const std::vector<ComplexNumbers>& OutSymbolstream, Bitstream& OutBitstream)
{
	for (ComplexNumbers Complex : OutSymbolstream)
	{
		if (Complex == ModulationSymbols[0])
		{
			
		}
	}
}

