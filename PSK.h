// (c) Spyridon Zervos


#pragma once

#include "Modulation.h"

class PSK : public Modulation
{
public:

	
	void ConvertToSymbols(Bitstream* InBitstream, std::vector<ComplexNumbers>& OutSymbolstream) override {}

	void ConvertToBinary(const std::vector<ComplexNumbers>& OutSymbolstream, Bitstream& OutBitstream) override {}

	// virtual ComplexNumbers* GetModulationSymbols() { return nullptr; }

	void PrintModulationSymbols() override {}

	void ConstellationDiagram() override {}
};