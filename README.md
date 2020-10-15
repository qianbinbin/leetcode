# LeetCode Solutions in C, C++, Java and Python

## C/C++

[CLion](https://www.jetbrains.com/clion/) is recommended.

**NOTE**: always reload CMake after adding new unit tests.

### Requirements

- A compiler with C99 and C++11 support.

### Manually

[CMake](https://cmake.org/) is required.

Generate a buildsystem:

```sh
$ cd /path/to/leetcode/c/  # /path/to/leetcode/cpp/
$ mkdir build
$ cd build
$ cmake ..
$ cd ..
```

CMake will automatically generate buildsystem files and download [googletest](https://github.com/google/googletest).

**NOTE**: always reload CMake after adding new unit tests.

To build, specify unit test with `--target`:

```sh
$ cmake --build build --target two_sum_test -- -j4
[  2%] Built target gtest
[ 97%] Built target lc
[ 97%] Built target gtest_main
Scanning dependencies of target two_sum_test
[100%] Building CXX object tests/CMakeFiles/two_sum_test.dir/two_sum_test.cpp.o
[100%] Linking CXX executable two_sum_test
[100%] Built target two_sum_test
```

Run the test:

```sh
$ ./build/tests/two_sum_test
Running main() from /path/to/leetcode/c/build/googletest-src/googletest/src/gtest_main.cc
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from two_sum_test
[ RUN      ] two_sum_test.twoSum_1_1
[       OK ] two_sum_test.twoSum_1_1 (0 ms)
[----------] 1 test from two_sum_test (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test
```

## Java

[IntelliJ IDEA](https://www.jetbrains.com/idea/) is recommended.

### Requirements

- JDK 8 or newer.

## Python

[PyCharm](https://www.jetbrains.com/pycharm/) is recommended.

### Requirements

- Python3.

### Manually

Run a specific unit test:

```shell
$ cd /path/to/leetcode/python/
$ python3 -m unittest tests/test_two_sum.py
.
----------------------------------------------------------------------
Ran 1 test in 0.000s

OK
```
