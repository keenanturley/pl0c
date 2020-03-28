# PL/0 Compiler - UCF COP3402 Project 3

## Authors

**Keenan Turley** <keenan.turley@knights.ucf.edu> and **Alexander Desmond** <alexdesmond@knights.ucf.edu>

## Introduction

This project is an implementation of a compiler for the PL/0 programming language in C.

This includes a lexicographical analyzer, parser, code generator, and virtual machine.
These modules are modified from their standalone programs into libraries for use in this part of the project.

The specifications of the each project part are provided in the `docs` folder.

To compile or run, first navigate to directory src:

```sh
cd src
```

## Compiling

Using GNU make:

```sh
make
```

## Running

Using shell

```sh
./compile [-l -a -v] (file-path)
```

Where `file-path` is the path to the source file you want to compile.

## Notes To the TA

- The test cases are in the `tests` directory
    - The sample.in / sample.out test case is the valid case.
    - All other cases correspond to errors

- Output is printed to stdout, which should be redirected if a test case output file is desired.

- If an error is encountered, a description of the error is printed to stderr and the program immediately exits
