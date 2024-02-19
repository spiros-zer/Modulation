// (c) Spyridon Zervos


#pragma once

#include "ComplexNumbers/ComplexNumbers.h"
#include "PSK.h"

class BPSK : public PSK
{
public:

    /******** GETTERS ********/
    
    /** @brief Singleton Getter */
    static BPSK& GetBPSKSystem() {return BPSKSystem_;}
    
    /******* DATA CONVERSION ********/
    
    void ConvertToSymbols(Bitstream* InBitstream, std::vector<ComplexNumbers>& OutSymbolstream) override;

    void ConvertToBinary(const std::vector<ComplexNumbers>& OutSymbolstream, Bitstream& OutBitstream) override;

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