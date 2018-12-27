# LeetCode Solutions in C, Java and Python


## Import as C Project

C99 and C++11 are required.


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
$ cd /path/to/your/project/leetcode/c/
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


## Import as Python Project

You can import the project with [PyCharm](https://www.jetbrains.com/pycharm/). Python 3 is required.


### Debug in Terminal

Run a specific unit test:

```shell
$ cd /path/to/your/project/leetcode/python/
$ python3 -m unittest tests/test_add_binary.py
..
----------------------------------------------------------------------
Ran 2 tests in 0.000s

OK
```

To run all unit tests:

```shell
$ python3 -m unittest discover tests/
.......................................................................................................................................................['5', '3', '.', '.', '7', '.', '.', '.', '.']
['6', '.', '.', '1', '9', '5', '.', '.', '.']
['.', '9', '8', '.', '.', '.', '.', '6', '.']
['8', '.', '.', '.', '6', '.', '.', '.', '3']
['4', '.', '.', '8', '.', '3', '.', '.', '1']
['7', '.', '.', '.', '2', '.', '.', '.', '6']
['.', '6', '.', '.', '.', '.', '2', '8', '.']
['.', '.', '.', '4', '1', '9', '.', '.', '5']
['.', '.', '.', '.', '8', '.', '.', '7', '9']

['5', '3', '4', '6', '7', '8', '9', '1', '2']
['6', '7', '2', '1', '9', '5', '3', '4', '8']
['1', '9', '8', '3', '4', '2', '5', '6', '7']
['8', '5', '9', '7', '6', '1', '4', '2', '3']
['4', '2', '6', '8', '5', '3', '7', '9', '1']
['7', '1', '3', '9', '2', '4', '8', '5', '6']
['9', '6', '1', '5', '3', '7', '2', '8', '4']
['2', '8', '7', '4', '1', '9', '6', '3', '5']
['3', '4', '5', '2', '8', '6', '1', '7', '9']
..................................
----------------------------------------------------------------------
Ran 185 tests in 0.026s

OK
```
