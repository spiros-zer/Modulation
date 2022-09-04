// (c) Spyridon Zervos


#pragma once

#include "Modulation.h"

class PSK : public Modulation
{
public:

	virtual ComplexNumber* GetModulationSymbols() override { return nullptr; }

	virtual void ConstellationDiagram() override {}
};