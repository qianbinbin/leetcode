cmake_minimum_required(VERSION 3.7)

project(leetcode)

add_subdirectory(src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif ()

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(1 test/two-sum.cpp)
target_link_libraries(1 lc)
target_link_libraries(1 gtest_main)
add_test(NAME 1_test COMMAND 1)

add_executable(4 test/median-of-two-sorted-arrays.cpp)
target_link_libraries(4 lc)
target_link_libraries(4 gtest_main)
add_test(NAME 4_test COMMAND 4)

add_executable(15 test/3sum.cpp)
target_link_libraries(15 lc)
target_link_libraries(15 gtest_main)
add_test(NAME 15_test COMMAND 15)

add_executable(16 test/3sum-closest.cpp)
target_link_libraries(16 lc)
target_link_libraries(16 gtest_main)
add_test(NAME 16_test COMMAND 16)

add_executable(18 test/4sum.cpp)
target_link_libraries(18 lc)
target_link_libraries(18 gtest_main)
add_test(NAME 18_test COMMAND 18)

add_executable(26 test/remove-duplicates-from-sorted-array.cpp)
target_link_libraries(26 lc)
target_link_libraries(26 gtest_main)
add_test(NAME 26_test COMMAND 26)

add_executable(27 test/remove-element.cpp)
target_link_libraries(27 lc)
target_link_libraries(27 gtest_main)
add_test(NAME 27_test COMMAND 27)

add_executable(31 test/next-permutation.cpp)
target_link_libraries(31 lc)
target_link_libraries(31 gtest_main)
add_test(NAME 31_test COMMAND 31)

add_executable(33 test/search-in-rotated-sorted-array.cpp)
target_link_libraries(33 lc)
target_link_libraries(33 gtest_main)
add_test(NAME 33_test COMMAND 33)

add_executable(36 test/valid-sudoku.cpp)
target_link_libraries(36 lc)
target_link_libraries(36 gtest_main)
add_test(NAME 36_test COMMAND 36)

add_executable(42 test/trapping-rain-water.cpp)
target_link_libraries(42 lc)
target_link_libraries(42 gtest_main)
add_test(NAME 42_test COMMAND 42)

add_executable(48 test/rotate-image.cpp)
target_link_libraries(48 lc)
target_link_libraries(48 gtest_main)
add_test(NAME 48_test COMMAND 48)

add_executable(60 test/permutation-sequence.cpp)
target_link_libraries(60 lc)
target_link_libraries(60 gtest_main)
add_test(NAME 60_test COMMAND 60)

add_executable(66 test/plus-one.cpp)
target_link_libraries(66 lc)
target_link_libraries(66 gtest_main)
add_test(NAME 66_test COMMAND 66)

add_executable(70 test/climbing-stairs.cpp)
target_link_libraries(70 lc)
target_link_libraries(70 gtest_main)
add_test(NAME 70_test COMMAND 70)

add_executable(73 test/set-matrix-zeroes.cpp)
target_link_libraries(73 lc)
target_link_libraries(73 gtest_main)
add_test(NAME 73_test COMMAND 73)

add_executable(80 test/remove-duplicates-from-sorted-array-ii.cpp)
target_link_libraries(80 lc)
target_link_libraries(80 gtest_main)
add_test(NAME 80_test COMMAND 80)

add_executable(81 test/search-in-rotated-sorted-array-ii.cpp)
target_link_libraries(81 lc)
target_link_libraries(81 gtest_main)
add_test(NAME 81_test COMMAND 81)

add_executable(89 test/gray-code.cpp)
target_link_libraries(89 lc)
target_link_libraries(89 gtest_main)
add_test(NAME 89_test COMMAND 89)

add_executable(128 test/longest-consecutive-sequence.cpp)
target_link_libraries(128 lc)
target_link_libraries(128 gtest_main)
add_test(NAME 128_test COMMAND 128)

add_executable(134 test/gas-station.cpp)
target_link_libraries(134 lc)
target_link_libraries(134 gtest_main)
add_test(NAME 134_test COMMAND 134)
