// (c) Spyridon Zervos


#pragma once

#include "ComplexNumbers/ComplexNumbers.h"
#include "PSK.h"

class BPSK : public PSK
{
public:

    /******** GETTERS ********/
    
    static BPSK& GetBPSKSystem() {return BPSKSystem_;}
    
    /******* MODULATION ********/
    
    void ConvertToSymbols(Bitstream* InBitstream, std::vector<ComplexNumbers>& OutSymbolstream) override;

    /******* DEMODULATION ********/
    
    void ConvertToBinary(const std::vector<ComplexNumbers>& Symbolstream, Bitstream& OutBitstream) override;

    /******** COSMETIC *******/

    void PrintModulationSymbols() override;

private:

    /** @brief Singleton instance */
    static BPSK BPSKSystem_;

    /******** CONSTRUCTORS/DESTRUCTORS ********/
    
    BPSK();
    
    BPSK(const BPSK&) = delete;
    
    ~BPSK() override;
    
    BPSK& operator=(const BPSK&) = delete;    
};