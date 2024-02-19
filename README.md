<header>
  <h2>Modulation</h2>
  <p>Custom implementation of Modulation schemes in C++.</p>
</header>

<section id="structure-section">
    <div> 
      <h2>Structuring</h2>
      <p>Since a Modulation scheme is a <em>system</em>, it is implemented as a singleton that can be called and provide functionality.</p>
      <h3>Current State</h3>
      <p><strong>Current state</strong> supports BPSK.</p>
    </div>
</section>

<section id="terminology-section">
    <div>
        <h2>Math terminology used</h2>
        <ul>
            <li>
                <p><em>Alphabet Size (M) &mdash;</em> is equal to the points on the constellation diagram and the number of symbols the modulation has. M = 2^N where N are the bits represented by the each symbol.</p>
            </li>
            <li>
                <p><em>Spectral Efficiency &mdash;</em> Spectral efficiency, spectrum efficiency or bandwidth efficiency refers to the information rate that can be transmitted over a given bandwidth in a specific communication system. Spectral efficiency = log2(M).</p>
            </li>
        </ul>
    </div>
</section>

<h2>ModulationBase</h2>
<p>The base entity of the modulation schemes. All the schemes derive from <strong>ModulationBase.h</strong>. Implementation can be found in Modulationbase.cpp</p>

```C++
class ModulationBase
```

<p>Defines base modulation features</p>

```C++
/** @brief The Alphabet Size (M) of the modulation. */
short unsigned AlphabetSize_{};

/** @brief Information rate that can be transmitted over a given bandwidth = log2(M). */
double SpectralEfficiency_{};

/** @brief The name of the modulation scheme. */
std::string ModulationName_;
```

<p>Core functions</p>

```C++
virtual void ConvertToSymbols(Bitstream* InBitstream, std::vector<ComplexNumber>& OutSymbolstream) = 0;

virtual void ConvertToBinary(const std::vector<ComplexNumber>& OutSymbolstream, Bitstream& OutBitstream) = 0;
```

<p>Other functions</p>

```C++
virtual void PrintModulationSymbols() = 0;

virtual void ConstellationDiagram() = 0;
```

<footer>
  <h2>Dependencies</h2>
  <p>This library uses the <a href="https://github.com/spiros-zer/ComplexNumbers">ComplexNumbers</a> and the <a href="https://github.com/spiros-zer/Bitstream">Bitstream</a> library. A <em>testbed</em> is offered where the capabilities of the CartesianCoordinates2D library can be tested in the <a href="https://github.com/spiros-zer/Testbed">Testbed</a> repository. </p>
</footer>
