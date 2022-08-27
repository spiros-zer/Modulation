// (c) Spyridon Zervos

#pragma once

#include "IModulation.h"

class BPSKModulation : public Modulation
{
private:

    virtual short unsigned GetAlphabet() override;

    virtual void GetModulationSymbols() override;

    virtual void ConstellationDiagram() override;

public:

    BPSKModulation()
    {
        M = 2;
    }
};