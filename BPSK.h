// (c) Spyridon Zervos


#pragma once

#include "ComplexNumber.h"
#include "PSK.h"

class BPSK : public PSK
{
public:

    BPSK();

    virtual ComplexNumber* GetModulationSymbols() override;

    virtual void PrintModulationSymbols() override;

    virtual void ConstellationDiagram() override;


    virtual void ConvertToSymbols(Bitstream* InBitstream, std::vector<ComplexNumber>& OutSymbolstream) override;

    virtual void ConvertToBinary(const std::vector<ComplexNumber>& OutSymbolstream, Bitstream& OutBitstream) override;

protected:

    ComplexNumber ModulationSymbols[2] = { {-1, 0}, {1, 0} };
};