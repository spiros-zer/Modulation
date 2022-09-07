// (c) Spyridon Zervos


#pragma once

#include "Modulation.h"

class PSK : public Modulation
{
public:

	virtual ComplexNumber* GetModulationSymbols() override { return nullptr; }

	virtual void PrintModulationSymbols() override {}

	virtual void ConstellationDiagram() override {}

	virtual void ConvertToSymbols(Bitstream* InBitstream, std::vector<ComplexNumber>& OutSymbolstream) override {}
};