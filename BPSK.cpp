// (c) Spyridon Zervos


#include "BPSK.h"

#include <cmath>

ComplexNumber* BPSK::GetModulationSymbols()
{
	return ModulationSymbols;
}

void BPSK::ConstellationDiagram()
{

}

BPSK::BPSK()
{
	M = 2;
	SpectralEfficiency = log2(M);
}
