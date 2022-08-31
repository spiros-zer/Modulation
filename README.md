# Modulation

> Implementation of various Modulation schemes *currently supporting NONE*.

## Table of Contents
```
1. Summary
2. Compilation of project
3. Useful Links
```
## Summary
All of the Modulations are derived from the Modulation Abstract class [and not Interface](https://cplusplus.com/forum/beginner/157568/) and differentiate depending on each Modulation scheme's prerequisites.

## Compilation of project
> To compile use the following commands:
```
mkdir obj 
```
> Make a directory to place the produced .obj s.
```
cl /c *.cpp /I C:\Users\spiro\Documents\Projects\ComplexNumbers /Fo".\obj\\"
```
> Compile all the .cpp in the current directory and put the produced .obj s in the obj directory.
```
link .\obj\*.obj
```
> Link the produced .obj s to create the .exe
> For further information on compiling options and capabilities see [compile to a DLL](https://medium.com/ai-innovation/how-to-create-c-c-dynamic-link-libraries-in-windows-28abefc988c9), [cl and link commands](https://docs.microsoft.com/en-us/cpp/build/reference/c-compile-without-linking?view=msvc-170)

## Useful Links
