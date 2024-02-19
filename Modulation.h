// (c) Spyridon Zervos


#pragma once

#include <vector>
#include <string>

struct ComplexNumbers;
class Bitstream;

class Modulation
{
    /** @brief The Alphabet Size (M) of the modulation. It is equal to the points on the Constellation Diagram 
     * and the number of Symbols of the Modulation. M = 2^N where N are the bits represented by the each symbol. */
    short unsigned AlphabetSize_{};

    /** @brief Spectral efficiency, spectrum efficiency or bandwidth efficiency refers to the information
     * rate that can be transmitted over a given bandwidth in a specific communication system.
     * Spectral efficiency = log2(M). */
    double SpectralEfficiency_{};

    /** @brief The name of the modulation scheme. */
    std::string ModulationName_;

public:

    /**** GETTERS/SETTERS */
    [[nodiscard]] std::string GetModulationName() const {return ModulationName_;}
    void SetModulationName(const std::string& InModulationName) {ModulationName_ = InModulationName;}

    [[nodiscard]] short unsigned GetAlphabetSize() const {return AlphabetSize_;}
    void SetAlphabetSize(const short unsigned& InAlphabetSize) {AlphabetSize_ = InAlphabetSize;} 

    [[nodiscard]] double GetSpectralEfficiency() const {return SpectralEfficiency_;}
    void SetSpectralEfficiency(const double& InSpectralEfficiency) {SpectralEfficiency_ = InSpectralEfficiency;}

    // [[nodiscard]] virtual ComplexNumbers* GetModulationSymbols() const = 0;

    /**** CORE */
    virtual void ConvertToSymbols(Bitstream* InBitstream, std::vector<ComplexNumbers>& OutSymbolstream) = 0;

    virtual void ConvertToBinary(const std::vector<ComplexNumbers>& OutSymbolstream, Bitstream& OutBitstream) = 0;

    /**** COSMETIC */
    virtual void PrintModulationSymbols() = 0;

    virtual void ConstellationDiagram() = 0;
};
