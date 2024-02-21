// (c) Spyridon Zervos


#include "BPSK.h"
#include "Bitstreams/Bitstream.h"
#include <cmath>
#include <iostream>

#include "CartesianCoordinates/CartesianCoordinates2D.h"

/******** SINGLETON INIT ********/
BPSK BPSK::BPSKSystem_;
/********************************/

void BPSK::ConvertToSymbols(Bitstream* InBitstream, std::vector<ComplexNumbers>& OutSymbolStream)
{
	for (const uint8_t& Byte : InBitstream->GetBitstream())
	{
		// std::cout << "Byte: " << std::hex << static_cast<int>(Byte) << "\n";
		for (int i = 7; i >= 0; --i)
		{
			const int bit = (Byte >> i) & 1;
			// std::cout << "bit: " << bit << " to Symbol: " << ModulationSymbols[bit].ToString() << '\n';
			OutSymbolStream.emplace_back(ModulationSymbols[bit]);
		}
	}
}

void BPSK::ConvertToBinary(const std::vector<ComplexNumbers>& Symbolstream, Bitstream& OutBitstream)
{
	uint8_t Byte{0};
	size_t BitPosition{0};
	for (const ComplexNumbers& Symbol : Symbolstream)
	{
		const uint8_t Value = Symbol.Complex->GetX() >= 0.5 ? 1 : 0;
		Byte |= Value << (7 - BitPosition++);

		if (BitPosition == 8)
		{
			OutBitstream.AddByte(Byte);
			Byte = 0;
			BitPosition = 0;
		}
	}
}

void BPSK::PrintModulationSymbols()
{
	std::cout << "Modulation Symbols of " << GetModulationName() << '\n';
	
	for (const ComplexNumbers& Symbol : ModulationSymbols)
	{
		std::cout << Symbol.ToString() << " ";
	}
	std::cout << '\n';
}

BPSK::BPSK()
{
	SetAlphabetSize(2);
	SetSpectralEfficiency(log2(GetAlphabetSize()));
	SetModulationName("BPSK");
	ModulationSymbols.emplace_back(0, 0);
	ModulationSymbols.emplace_back(1, 0);
}

BPSK::~BPSK()
{
	// Cleanup code, if any
}
