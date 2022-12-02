# Sovellusohjelmointi Assignment 1

This is a program that reads a file or input from terminal
and sends the text via POSIX signals like SIGUSR1.

## Installation

This program can be installed by running
```
cmake .
make
```
in the source code folder

## Usage

```
Usage: ./sovohj [input|-] [output|-]

Example:
./sovohj - testfile2 [starts to ask for input]
HEIPPARALLAA 1234

HEI HEI
[press ctrl + D --> program closes]

cat testfile
HEIPPARALLAA*1234**HEI*HEI*% 

```
Use CAPITAL LETTERS

Press ^D to send EOF when using '-' as the first argument.
It closes the standard input (stdin).

Logging in "as1_log" file

Filenames "as1_log" and "as1_temp" are reserved for the program.


## Source code
- sovohj.c / sovohj binary:
  - first main function, parses and passes input arguments
- child_exec.c / child_exec binary:
  - exec'd program that reads text, sends and receives
  morse signals and writes to child
  - uses fork to create parent and child processes
- morse.c, morse.h:
  - library that has functions for processing text and signals

## Notes

Created by Otso Luukkanen 8.11.2022.
This assignment is a part of Aalto University course
ELEC-C7310 - Sovellusohjelmointi, 5.9.2022-8.12.2022.
This course is hosted by lecturer Risto Järvinen.
