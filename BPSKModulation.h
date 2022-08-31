// (c) Spyridon Zervos

#pragma once

#include "Modulation.h"
#include <vector>
#include "ComplexNumbersLibrary.h"

class BPSKModulation : public Modulation
{
private:

    virtual void GetModulationSymbols() override;

    virtual void ConstellationDiagram() override;

protected:

    

public:

    BPSKModulation();
};