// (c) Spyridon Zervos


#pragma once

class Modulation
{
public:

    short unsigned GetAlphabet();

    double GetSpectralEfficiency();

    virtual void GetModulationSymbols() = 0;

    virtual void ConstellationDiagram() = 0;

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
};
