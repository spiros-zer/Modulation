// (c) Spyridon Zervos


#pragma once

#include "ComplexNumber.h"
#include "PSK.h"

class BPSK : public PSK
{
public:

    BPSK();

    virtual ComplexNumber* GetModulationSymbols() override;

    virtual void ConstellationDiagram() override;

    virtual void ConvertToSymbols(const Bitstream* InBitstream, std::vector<ComplexNumber>& OutSymbolstream) override;

protected:

    ComplexNumber ModulationSymbols[2] = { {1, 0}, {-1, 0} };
};