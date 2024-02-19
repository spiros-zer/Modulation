// (c) Spyridon Zervos


#pragma once

#include "ComplexNumbers/ComplexNumbers.h"
#include "PSK.h"

class BPSK : public PSK
{
public:

    /**** GETTERS/SETTERS */
    /** @brief Singleton Getter */
    static BPSK& GetBPSKSystem();
    
    /**** CORE */
    void ConvertToSymbols(Bitstream* InBitstream, std::vector<ComplexNumbers>& OutSymbolstream) override;

    void ConvertToBinary(const std::vector<ComplexNumbers>& OutSymbolstream, Bitstream& OutBitstream) override;

    /**** COSMETIC */
    // ComplexNumbers* GetModulationSymbols() override;

    void PrintModulationSymbols() override;

    void ConstellationDiagram() override;

    ComplexNumbers ModulationSymbols[2] = { {-1, 0}, {1, 0} };

private:

    /** @brief Singleton instance */
    static BPSK instance;

    /**** CONSTRUCTORS/DESTRUCTORS */
    BPSK();
    ~BPSK();
    BPSK(const BPSK&) = delete;
    BPSK& operator=(const BPSK&) = delete;    
};