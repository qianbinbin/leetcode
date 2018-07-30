# LeetCode Solutions in C and Java

## Import as C Project

### CLion

This project can be imported by [CLion](https://www.jetbrains.com/clion/) directly.

### CMake

If you are using CLion, you don't need to install CMake, as CLion has a CMake build system with it.

Install [CMake](https://cmake.org/download/)

## Build and Run

**NOTE: Once a new `*.cpp` test file is added under `src/test/c/`, you should reload CMake configuration immediately.**

### In CLion

After reloading CMake project automatically, select a configuration in the Toolbar, and click the 'Run' button.

### In Terminal

Change directry to your project:

```shell
$ cd /path/to/your/project/leetcode/
```

If it's your first time to use CMake, create a directory for cache files, and then reload CMake configuration:

```shell
$ mkdir cmake-build-debug
$ cd cmake-build-debug
$ cmake ..
$ cd ..
```

CMake will automatically create CMake cache files and download [googletest](https://github.com/google/googletest).

Build with CMake:

```shell
$ cmake --build cmake-build-debug --target 3sum_closest_test -- -j 4
```

You can change the parameter of `--target` to other targets, which are the same as file names under `src/test/c/`.

Run:

```shell
$ cmake-build-debug/3sum_closest_test
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from three_sum_closest_test
[ RUN      ] three_sum_closest_test.threeSumClosest_16_1
[       OK ] three_sum_closest_test.threeSumClosest_16_1 (0 ms)
[----------] 1 test from three_sum_closest_test (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (1 ms total)
[  PASSED  ] 1 test.
```


## Import as Java Project

Java 8 or newer is required.

You can import the project with [IntelliJ IDEA](https://www.jetbrains.com/idea/). JUnit5.0 is required for unit testing.
