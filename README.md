# Template For C++ Projects

This is a template for C++ projects based off of [franneck94's CppProjectTemplate](https://github.com/franneck94/CppProjectTemplate). Here's what you get:

- Library, executable and test code separated in distinct folders
- Use of modern CMake for building and compiling
- External libraries installed and managed by
  - [Conan](https://conan.io/) Package Manager OR
  - [Manual Inclusion](#manual-dependency-inclusion)
- Unit testing using [Gtest](https://github.com/google/googletest)
- Example use of general purpose library use (such as [fmt](https://github.com/fmtlib/fmt))
- Continuous integration testing with Github Actions and [pre-commit](https://pre-commit.com/)
- Code coverage reports, including automatic upload to [Codecov](https://codecov.io)
- Code documentation with [Doxygen](https://doxygen.nl/)
- Tooling: Clang-Format, Cmake-Format, Clang-tidy (static analysis), Sanitizers
- Easy Warning Configuration (see cmake/Warnings.cmake)

## Structure

``` text
├── CMakeLists.txt
├── app
│   ├── CMakesLists.txt
│   └── main.cc
├── cmake
│   └── cmake modules
├── docs
│   ├── Doxyfile
│   └── html/
├── external
│   ├── ...
├── src
│   ├── CMakesLists.txt
│   ├── my_lib.h
│   └── my_lib.cc
└── tests
    ├── CMakeLists.txt
    └── main.cc
```

Library code goes into [src/](src/), main program code in [app/](app) and tests go in [tests/](tests/).

## Software Requirements
### Mandatory
- CMake 3.21+
- Dependency Management (any of the below):
  * Conan 2.0+
  * Git for fetching submodule internet connected machines. If an internet connection is unavailable, see [here](#manual-dependency-inclusion))
- MSVC 2017 (or higher), G++9 (or higher), Clang++9 (or higher)

### Optional
- LLVM Toolchain 17.0+ (clang-format, clang-tidy)
- Doxygen
- Code Coverage (only on GNU or Clang): lcov, gcovr
- Graphviz

## External Software Dependencies
- fmtlib (version 9.1.0+)
- gtest (version 1.14.0+)

## Building

All commands are written assuming linux or git bash is being used. It is also written assuming you are building for Release (if Debug is desired, replace Release with Debug as needed)

First, clone this repo and do the preliminary work:

```shell
git clone http://url/to/repository.git
```

Create and change into the build directory (git bash):
```
rm -rf build
mkdir build 
cd build
```

If using conan, resolve dependencies (if not, see [see here](#manual-dependency-inclusion)
```
conan install .. -s build_type=Release --output-folder=. --build missing -s compiler.cppstd=17
```

Building the App Executable

```shell
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release --target main
cd app
./main
```

- Unit testing

```shell
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug --target unit_tests
cd tests
./unit_tests
```

- Documentation

```shell
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug --target docs
```

- Code Coverage (Unix only -- Debug is required!)

```shell
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_COVERAGE=ON ..
cmake --build . --config Debug --target coverage
```

## Manual Dependency Inclusion
If Conan is unavailable as a package manager, the cmake scripts will attempt to look for the required dependencies in the "external" folder. The user will be expected to place the required dependencies as follows:

```text
├── CMakeLists.txt
├── app
├── cmake
├── docs
├── external
│   ├── <dependency1>
│       └── <dependency1 repository files>
|   └── <dependency2>
│       └── <dependency2 repository files>
├── src
└── tests
```

Note that the names should match what is specified in [this section](#external-software-dependencies).

When using CMake builds conan must be set to disabled through the "USE_CONAN" option. This can be done by editting the global CMakeLists.txt or through a command line argument. For example:

```
cmake -DCMAKE_BUILD_TYPE=Release -DUSE_CONAN=OFF ..
```



