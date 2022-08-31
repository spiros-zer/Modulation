// (c) Spyridon Zervos


#include "BPSKModulation.h"

#include "ComplexNumbersLibrary.h"
#include <cmath>

void BPSKModulation::GetModulationSymbols()
{

}

void BPSKModulation::ConstellationDiagram()
{

}

BPSKModulation::BPSKModulation()
{
	M = 2;
	SpectralEfficiency = log2(M);
}
