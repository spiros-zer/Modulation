// (c) Spyridon Zervos


#pragma once

#include <vector>
#include <string>

class ComplexNumber;
class Bitstream;

class Modulation
{
public:

    /**
     * @brief Gets Name object.
     * 
     * @return The Name of the Modulation.
     */
    std::string GetModulationName() {return Name;}

    short unsigned GetAlphabet() {return M;}

    double GetSpectralEfficiency() {return SpectralEfficiency;}

    virtual ComplexNumber* GetModulationSymbols() = 0;

    virtual void PrintModulationSymbols() = 0;

    virtual void ConstellationDiagram() = 0;

    virtual void ConvertToSymbols(Bitstream* InBitstream, std::vector<ComplexNumber>& OutSymbolstream) = 0;

    virtual void ConvertToBinary(const std::vector<ComplexNumber>& OutSymbolstream, Bitstream& OutBitstream) = 0;

protected:

    /**
     * @brief The Alphabet Size of the modulation. It is equal to the points on the Constellation Diagram 
     * and the number of Symbols of the Modulation.
     * M = 2^N where N are the bits represented by the each symbol.
     */
    short unsigned M;

    /**
     * @brief Spectral efficiency, spectrum efficiency or bandwidth efficiency refers to the information
     * rate that can be transmitted over a given bandwidth in a specific communication system.
     * Spectral efficiency = log2(M).
     */
    double SpectralEfficiency;

    /**
     * @brief The name of the modulation scheme.
     */
    std::string Name;
};
