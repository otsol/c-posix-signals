# Sovellusohjelmointi Assignment 1

This is a program that reads a file or input from terminal
and sends the text via POSIX signals like SIGUSR1.

## Installation

This program can be installed by running
```bash
make
```
in the source code folder

## Usage

```bash
Usage: ./sovohj [input|-] [output|-]
Example: ./sovohj - testfile2
```

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
