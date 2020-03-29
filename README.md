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

- The test cases are in the `tests` directory, with inputs and outputes being in the `in` and `out` folders, respectively

  - Each test case output is run with all flags enabled

  - The files prefixed with `sample` are input and output of a valid test case.

  - All other cases correspond to errors

  - The test script `run_tests.sh` is provided for your convinience in the root directory.

    - This generates a `.out` file for each `.in` file in the `tests` directory by running the command:

        ```bash
        ./src/compile -l -a -v ./tests/in/$TEST_NAME.in > ./tests/out/$TEST_NAME.out
        ```

- Output is printed to `stdout`, which should be redirected if a test case output file is desired.

- If an error is encountered, a description of the error is printed to `stdout` and the program immediately exits

  - `stderr` is not used for this because the test case output must include the error, which cannot be redirected to a file from the shell
