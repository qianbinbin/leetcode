# LeetCode Solutions in C

## Import Project

### CLion

This project can be imported by [CLion](https://www.jetbrains.com/clion/) directly.

### CMake

If you are using CLion, you don't need to install CMake, as CLion has a CMake build system with it.

[Install CMake](https://cmake.org/download/)

## Build and Run

### In CLion

After reloading CMake project automatically, select a configuration in the Toolbar, and click the 'Run' button.

### In Terminal

Change directry to your project:

```shell
$ cd /path/to/your/project/leetcode/
```

If it's your first time to use CMake, create a directory for cache files, and then reload project:

```shell
$ mkdir cmake-build-debug
$ cd cmake-build-debug
$ cmake ..
$ cd ..
```

CMake will automatically create CMake cache files and download [googletest](https://github.com/google/googletest).

Build with CMake:

```shell
$ cmake --build cmake-build-debug --target 42 -- -j 4
```

You can change the parameter of `--target` to other targets configured in `CMakeLists.txt`, or add your own configurations there.

Run:

```shell
$ cmake-build-debug/42
Running main() from gtest_main.cc
[==========] Running 2 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 1 test from leetcode_42_1
[ RUN      ] leetcode_42_1.normal
[       OK ] leetcode_42_1.normal (0 ms)
[----------] 1 test from leetcode_42_1 (0 ms total)

[----------] 1 test from leetcode_42_2
[ RUN      ] leetcode_42_2.normal
[       OK ] leetcode_42_2.normal (0 ms)
[----------] 1 test from leetcode_42_2 (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 2 test cases ran. (0 ms total)
[  PASSED  ] 2 tests.
```
