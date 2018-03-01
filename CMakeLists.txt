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

add_executable(2 test/add-two-numbers.cpp)
target_link_libraries(2 lc)
target_link_libraries(2 gtest_main)
add_test(NAME 2_test COMMAND 2)

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

add_executable(19 test/remove-nth-node-from-end-of-list.cpp)
target_link_libraries(19 lc)
target_link_libraries(19 gtest_main)
add_test(NAME 19_test COMMAND 19)

add_executable(24 test/swap-nodes-in-pairs.cpp)
target_link_libraries(24 lc)
target_link_libraries(24 gtest_main)
add_test(NAME 24_test COMMAND 24)

add_executable(25 test/reverse-nodes-in-k-group.cpp)
target_link_libraries(25 lc)
target_link_libraries(25 gtest_main)
add_test(NAME 25_test COMMAND 25)

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

add_executable(61 test/rotate-list.cpp)
target_link_libraries(61 lc)
target_link_libraries(61 gtest_main)
add_test(NAME 61_test COMMAND 61)

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

add_executable(82 test/remove-duplicates-from-sorted-list-ii.cpp)
target_link_libraries(82 lc)
target_link_libraries(82 gtest_main)
add_test(NAME 82_test COMMAND 82)

add_executable(83 test/remove-duplicates-from-sorted-list.cpp)
target_link_libraries(83 lc)
target_link_libraries(83 gtest_main)
add_test(NAME 83_test COMMAND 83)

add_executable(86 test/partition-list.cpp)
target_link_libraries(86 lc)
target_link_libraries(86 gtest_main)
add_test(NAME 86_test COMMAND 86)

add_executable(89 test/gray-code.cpp)
target_link_libraries(89 lc)
target_link_libraries(89 gtest_main)
add_test(NAME 89_test COMMAND 89)

add_executable(92 test/reverse-linked-list-ii.cpp)
target_link_libraries(92 lc)
target_link_libraries(92 gtest_main)
add_test(NAME 92_test COMMAND 92)

add_executable(128 test/longest-consecutive-sequence.cpp)
target_link_libraries(128 lc)
target_link_libraries(128 gtest_main)
add_test(NAME 128_test COMMAND 128)

add_executable(134 test/gas-station.cpp)
target_link_libraries(134 lc)
target_link_libraries(134 gtest_main)
add_test(NAME 134_test COMMAND 134)

add_executable(135 test/candy.cpp)
target_link_libraries(135 lc)
target_link_libraries(135 gtest_main)
add_test(NAME 135_test COMMAND 135)

add_executable(136 test/single-number.cpp)
target_link_libraries(136 lc)
target_link_libraries(136 gtest_main)
add_test(NAME 136_test COMMAND 136)

add_executable(137 test/single-number-ii.cpp)
target_link_libraries(137 lc)
target_link_libraries(137 gtest_main)
add_test(NAME 137_test COMMAND 137)

add_executable(138 test/copy-list-with-random-pointer.cpp)
target_link_libraries(138 lc)
target_link_libraries(138 gtest_main)
add_test(NAME 138_test COMMAND 138)

add_executable(141 test/linked-list-cycle.cpp)
target_link_libraries(141 lc)
target_link_libraries(141 gtest_main)
add_test(NAME 141_test COMMAND 141)

add_executable(142 test/linked-list-cycle-ii.cpp)
target_link_libraries(142 lc)
target_link_libraries(142 gtest_main)
add_test(NAME 142_test COMMAND 142)
