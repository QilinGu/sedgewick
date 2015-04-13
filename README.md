# Algorithsm 4th Edition

[![Build Status](https://travis-ci.org/ksamdev/sedgewick.svg?branch=master)](https://travis-ci.org/ksamdev/sedgewick)


## Outline

- [Overview](#overview)
- [Tree](#tree)
- [Build](#build)
- [Test](#test)
- [Study](#study)


## Overview

Problems and solutions for Algorithms 4th Ed by Robert Sedgewick.

The project is written in C++ using [Google Style](https://google-styleguide.googlecode.com/svn/trunk/cppguide.html).

The source code is available in `src/chN/sM` folders where `N` denotes a chapter
and `M` is corresponding section.

Every chapter, section, exercise has its own unique namespace, e.g.
`ch1::s1::ex9`.  The project uses
[Google Test](https://code.google.com/p/googletest/) and
[Google Mock](https://code.google.com/p/googlemock/) libraries to cover
every problem with unit-tests.

There is a special `cmake` rule for studying called `STUDY`.  It allows one to
use templates from `src/chN/sM/study`, fill in the code and run unit-test to
re-do exercises.


## Tree

Source code is put into `src/ch*/s*` folders. Every problem has at least three
files:

  - `ex_N.h` interface
  - `ex_N.cc` implementation
  - `ex_N_test.cc` unit-test(s)

Exercise implementation templates are available in `src/ch*/s*/study`.

Example:

```sh
% tree -P 'ex_9*.h|ex_9*.cc' src
src
└── ch1
    └── s1
        ├── ex_9.cc         # implementation
        ├── ex_9.h          # interface
        ├── ex_9_test.cc    # unit-test
        └── study
            └── ex_9.cc     # study template (implementation)
```


## Build

First create a folder for the build and generate Makefiles:

```sh
% mkdir build && cd build
% cmake ..
```

The entire package can be built with a single command:

```sh
% make
```

It is a good idea to run the compilation in parallel with `-j 2` (two processes)
option.

For clarity of the output external libraries can be built first:

```sh
% make -j 2 -C ext
```

Then build the rest of the code:

```sh
% make -j 2
```

Or build a single section:

```sh
% make -j 2 -C src/ch1/s1
```


## Test

Every exercise runs through unit-tests to ensure proper work.  Use following
command to run all tests from the build folder:

```sh
% make test
```

One may run only tests for a single section:

```sh
% make test -C src/ch1/s1
```

All unit tests can be found in `src/chN/sM/` folder.  Test executables have `ut_`
prefix.


## Study

The project has a special `cmake` rule `STUDY` that can be used to re-do some
exercises.  The rule builds source code in `src/ch*/s*/study` folders instead of
`src/ch*/s*/src`.  The `study` folders hold empty interface templates for
exercise.

Feel free to fill code in these templates but **DO NOT COMMIT** the `study`
folders.  They are designed to remain empty for studies.

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
% make -j 2 -C src/ch1/s1
% make test -C src/ch1/s1
```
