This repository hosts a visual studio version of the ISDA CDS standard model original code that is available at https://www.cdsmodel.com/

The available documentation about the model does not specify entirely the implementation so that the code is important in itself for it fill the little gaps in the specification.

Being important, the code should be immediately usable and debuggable, which is not the case under windows as the code is (C code) to build with nmake, and therefore to debug with windbg, the other solution being to create a visual studia makefile project, which is not really vanilla.

This is the reason why I integrated the original C code (base on a pre 2007 version of the Excel C API) in a visual studio 2022 dll/xll solution, making available the last version of the Excel C API, and yielding this repository.

The solution file is in /ISDA_ME

xll files are in /ISDA_ME/(Configuration) for the x86 plateform and in /ISDA_ME/x64/(Configuration) for the x64 platform. The original "test" spreadsheet from http://www.cdsmodel.com/ is available in /ISDA_ME

As you see the repo has (and will forever have) only one commit. If out of pure luck you manage to succeed in contacting me regarding this repository, I will not answer.