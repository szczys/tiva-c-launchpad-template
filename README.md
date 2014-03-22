Tiva C Launchpad Template
=========================

This is a template for building projects for Texas Instruments (TI) ARM processors; specifically the TM4C123GH6PMI that ships on the Tiva C Launchpad. But just a bit of alteration should make it cover the range of chips in the same family.

Dependencies
------------

1. You must have an ARM cross compiler (arm-none-eabi-***) installed and in your system path. I recommend the [Sourcery CodeBench](http://www.mentor.com/embedded-software/sourcery-tools/sourcery-codebench/editions/lite-edition/) Lite package as I've tried compiling my own tools before and it can be a real network of rabbit holes when it comes to dependencies and supporting all of the features of these chips (hardware floating point for STM32 comes to mind).

2. You must have the [TivaWare](http://www.ti.com/tool/sw-tm4c) package installed. The path to this file must be listed in the Makefile included in this repository

3. OpenOCD must be installed in order to flash your program to the board (the command to flash your binary is: make program)

Gotchas
------- 

TI has a restrictive license on all of their example files. Becuase of this you cannot use their Makefiles, Linker scripts, or Startup code in open source repositories.

This template gets around this issue by creating symbolic links to these files. You need the TivaWare package for libraries anyway, this simply creates links to the pertinent files at compile time.

Beware as the linker script and startup code may not work in every case.
