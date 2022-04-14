# `libnds` Project Template
This is a general template I use for writing programs for the Nintendo DS using devkitPro's `libnds`. A brief overview of how it's used:
## Folder Layout
The general directory structure is as follows:
- `.vscode/` - Config files for Visual Studio Code to provide Intellisense and get rid of annoying red squiggles. You may need to change the `compilerPath` key in `c_cpp_properties.json` according to your system configuration. If you clone this repository for future templates, these files will be ignored.
- `include/` - Place any header files to be included here.
- `source/` - Place your `.c` or `.cpp` files here.
