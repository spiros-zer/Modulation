// (c) Spyridon Zervos


#pragma once

#include <memory>
#include <vector>
#include <string>

struct ComplexNumbers;
class Bitstream;

class Modulation
{
public:

    /******** DESTRUCTOR ********/
    
    virtual ~Modulation() = default;

    /******* GETTERS ********/
    
    [[nodiscard]] std::string GetModulationName() const {return ModulationName_;}

    [[nodiscard]] short unsigned GetAlphabetSize() const {return AlphabetSize_;}

    [[nodiscard]] double GetSpectralEfficiency() const {return SpectralEfficiency_;}

    [[nodiscard]] virtual std::vector<ComplexNumbers> GetModulationSymbols() const {return ModulationSymbols;} 

    /******* DATA CONVERSION ********/
    
    virtual void ConvertToSymbols(Bitstream* InBitstream, std::vector<ComplexNumbers>& OutSymbolstream) = 0;

    virtual void ConvertToBinary(const std::vector<ComplexNumbers>& OutSymbolstream, Bitstream& OutBitstream) = 0;

    /******** COSMETIC ********/
    
    virtual void PrintModulationSymbols() = 0;

protected:

    std::vector<ComplexNumbers> ModulationSymbols;

    /******** SETTERS ********/

    void SetModulationName(const std::string& InModulationName) {ModulationName_ = InModulationName;}

    void SetAlphabetSize(const short unsigned& InAlphabetSize) {AlphabetSize_ = InAlphabetSize;}

    void SetSpectralEfficiency(const double& InSpectralEfficiency) {SpectralEfficiency_ = InSpectralEfficiency;}
    
private:

    /** @brief Alphabet size (or M) of the modulation. */
    short unsigned AlphabetSize_{};

    /** @brief Rate at which info can be transmitted over a given bandwidth. */
    double SpectralEfficiency_{};

    /** @brief The name of the modulation scheme. */
    std::string ModulationName_;
};
