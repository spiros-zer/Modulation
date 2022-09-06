// (c) Spyridon Zervos


#include "BPSK.h"
#include "Bitstream.h"
#include <cmath>

ComplexNumber* BPSK::GetModulationSymbols()
{
	return ModulationSymbols;
}

void BPSK::ConstellationDiagram()
{

}

void BPSK::ConvertToSymbols(const Bitstream* InBitstream, std::vector<ComplexNumber>& OutSymbolStream)
{

}

BPSK::BPSK()
{
	M = 2;
	SpectralEfficiency = log2(M);
}
