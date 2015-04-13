# Algorithsm 4th Edition

[![Build Status](https://travis-ci.org/ksamdev/sedgewick.svg?branch=master)](https://travis-ci.org/ksamdev/sedgewick)


## Outline

- [Overview](#overview)
- [Build](#build)
- [Test](#test)
- [Study](#study)


## Overview

Problems and solutions for Algorithms 4th Ed by Robert Sedgewick.

The project is written in C++ rather than Java.  Problems source code is
available in `chN/sM/src` (chapter `N`, section `M`) folders.  Every problem is
covered with unit-tests.

There is a special `cmake` rule for studying called `STUDY`.  It allows one to
use templates from `chN/sM/study`, fill in the code and run unit-test to re-do
the exercise.


## Build

First create a folder for the build and generate Makefiles:

```sh
% mkdir build && cd build
% cmake ..
```

The entire package can be built with single command:

```sh
% make
```

It is a good idea to run compilation in parallel with `-j 2` (two processes)
option.

For clarity of the output external libraries can be built first:

```sh
% make -j 2 -C ext
```

Then build the rest of the code:

```sh
% make -j 2
```

Or build specific section:

```sh
% make -j 2 -C ch1/s1
```


## Test

Every exercise runs through unit-tests to ensure proper work.  Use following
command to run all tests from the build folder:

```sh
% make test
```

One may run only tests for specific section:

```sh
% make test -C ch1/s1
```

All unit tests can be found in `chN/sM/ut` folder where `chN/sM` must be replaced
with corresponding chapter and section number, e.g. `ch1/s1` - chapter 1,
section 1.


## Study

The project has a special `cmake` rule `STUDY` that can be used to re-do
exercises.  The rule uses code templates from `ch*/s*/study` folders instead of
`ch*/s*/src`.

Feel free to fill code in these templates but **DO NOT COMMIT** `study` folders.
They are designed to stay empty for studes.

It is advised to build studies in a separate build folder:

```sh
% mkdir study && cd study
% cmake -DSTUDY:BOOL=Yes ..
% make -j 2 -C ext
```

The entire project can be built with `make -j 2` but all unit tests will fail
if `make test` is run.  Therefore it is advised to work on one section at a
time, e.g.:

```sh
% make -j 2 -C ch1/s1
% make test -C ch1/s1
```
