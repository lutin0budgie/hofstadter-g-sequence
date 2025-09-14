# The Hofstadter G-Sequence (C++)

You can find the instructions for this lab at [More Than Equations][more-than-equations]. Create a new repository on GitHub to house your code. Be sure to make the repository public so that I can view and grade it.

We will use [CMake][cmake] to build executables (e.g. tests, the driver program, the benchmarks, etc.). Additionally, we will use [Catch2][catch2] for unit testing and benchmarking.

## Building Executables With CMake

You can use CMake to compile and build the executables for the project. First, you need to create a `build/` directory in the project. The build directory will house all of the compiled files as well as the `Makefile` for the project. Note that we do NOT check the `build/` directory into version control since each person will have to regenerate the executables on their own machine.

```bash
mkdir build
cd build
```

Once you are inside of the build directory, you can run the following command to build all of the executables for the project:

```bash
cmake .. && make
```

## Testing the App

Any tests that you define in the `tests/` directory must have a corresponding entry in `CMakeLists.txt`. After you build executables using CMake, you can run the corresponding test files from within the `build/` directory.

## Running the App

The `main.cpp` file at the root of the project must have a corresponding entry in `CMakeLists.txt`. After you build executables using CMake, you can run the driver program from within the `build/` directory.

## Running Benchmarks

Benchmarking is provided with Catch2. You can write benchmarking assertions alongside test assertions right in your test files.

[catch2]: https://github.com/catchorg/Catch2
[cmake]: https://cmake.org/
[more-than-equations]: https://morethanequations.com/Computer-Science/Labs/The-Hofstadter-G-Sequence
