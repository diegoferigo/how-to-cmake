[![Build Status](https://travis-ci.org/diegoferigo/how-to-cmake.svg?branch=master)](https://travis-ci.org/diegoferigo/how-to-cmake)

# Demo repository for CMake-based projects

This repository contains a template tree of sources for building / installing / exporting / importing libraries and executables with CMake.

## Project 1

*   `Lib1`: standalone
*   `Main1`: links with `Lib1`

#### Build and install:

```sh
cd Project1
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=$(pwd)/../../install/Project1 ..
make && make install
CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH:$(pwd)/../../install/Project1
```

#### Run:

```sh
./Main1
```

## Project2

(TODO: switch to `COMPONENTS`)

*   `Lib2`: standalone
*   `Lib3`: links with `Lib2`
*   `Main2`: links with `Lib3`

This project shows how to handle a library project split in different parts.

Two use cases are considered:
1.   `Main2`: is an in-tree executable used as unit test of the `Lib2` and `Lib3`
2.   `Project3`: is an external project that imports and links against these libraries

#### Build and install:

```sh
cd Project2
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=$(pwd)/../../install/Project2 ..
make && make install
CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH:$(pwd)/../../install/Project2
```

#### Run:

```sh
./Main2
```

## Project3

*   `Main3`: links with either the installed `Lib1` library, and the `Lib3` component

The import of `Lib1` is straightforward.

In the `Lib3` case, `find_package(Lib3)` should look for an installed `Lib3` _and_ also its
dependencies (`Lib2`), setting implicitly all the required `include_directories()`.

#### Build and install:

```sh
cd Project3
mkdir build && cd build
cmake ..
make
```

#### Run:

```sh
./Main3
```

### References
*   [Module vs Config](https://github.com/ruslo/hunter/wiki/example.find_package.config)
