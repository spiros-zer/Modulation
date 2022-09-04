// (c) Spyridon Zervos


#pragma once

#include "ComplexNumber.h"
#include "PSK.h"
#include <vector>

class BPSK : public PSK
{
public:

    BPSK();

    virtual ComplexNumber* GetModulationSymbols() override;

    virtual void ConstellationDiagram() override;

protected:

    ComplexNumber ModulationSymbols[2] = { {1, 0}, {-1, 0} };
};