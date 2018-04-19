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

add_executable(5 test/longest-palindromic-substring.cpp)
target_link_libraries(5 lc)
target_link_libraries(5 gtest_main)
add_test(NAME 5_test COMMAND 5)

add_executable(8 test/string-to-integer-atoi.cpp)
target_link_libraries(8 lc)
target_link_libraries(8 gtest_main)
add_test(NAME 8_test COMMAND 8)

add_executable(10 test/regular-expression-matching.cpp)
target_link_libraries(10 lc)
target_link_libraries(10 gtest_main)
add_test(NAME 10_test COMMAND 10)

add_executable(12 test/integer-to-roman.cpp)
target_link_libraries(12 lc)
target_link_libraries(12 gtest_main)
add_test(NAME 12_test COMMAND 12)

add_executable(13 test/roman-to-integer.cpp)
target_link_libraries(13 lc)
target_link_libraries(13 gtest_main)
add_test(NAME 13_test COMMAND 13)

add_executable(14 test/longest-common-prefix.cpp)
target_link_libraries(14 lc)
target_link_libraries(14 gtest_main)
add_test(NAME 14_test COMMAND 14)

add_executable(15 test/3sum.cpp)
target_link_libraries(15 lc)
target_link_libraries(15 gtest_main)
add_test(NAME 15_test COMMAND 15)

add_executable(16 test/3sum-closest.cpp)
target_link_libraries(16 lc)
target_link_libraries(16 gtest_main)
add_test(NAME 16_test COMMAND 16)

add_executable(17 test/letter-combinations-of-a-phone-number.cpp)
target_link_libraries(17 lc)
target_link_libraries(17 gtest_main)
add_test(NAME 17_test COMMAND 17)

add_executable(18 test/4sum.cpp)
target_link_libraries(18 lc)
target_link_libraries(18 gtest_main)
add_test(NAME 18_test COMMAND 18)

add_executable(19 test/remove-nth-node-from-end-of-list.cpp)
target_link_libraries(19 lc)
target_link_libraries(19 gtest_main)
add_test(NAME 19_test COMMAND 19)

add_executable(20 test/valid-parentheses.cpp)
target_link_libraries(20 lc)
target_link_libraries(20 gtest_main)
add_test(NAME 20_test COMMAND 20)

add_executable(21 test/merge-two-sorted-lists.cpp)
target_link_libraries(21 lc)
target_link_libraries(21 gtest_main)
add_test(NAME 21_test COMMAND 21)

add_executable(23 test/merge-k-sorted-lists.cpp)
target_link_libraries(23 lc)
target_link_libraries(23 gtest_main)
add_test(NAME 23_test COMMAND 23)

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

add_executable(28 test/implement-strstr.cpp)
target_link_libraries(28 lc)
target_link_libraries(28 gtest_main)
add_test(NAME 28_test COMMAND 28)

add_executable(31 test/next-permutation.cpp)
target_link_libraries(31 lc)
target_link_libraries(31 gtest_main)
add_test(NAME 31_test COMMAND 31)

add_executable(32 test/longest-valid-parentheses.cpp)
target_link_libraries(32 lc)
target_link_libraries(32 gtest_main)
add_test(NAME 32_test COMMAND 32)

add_executable(33 test/search-in-rotated-sorted-array.cpp)
target_link_libraries(33 lc)
target_link_libraries(33 gtest_main)
add_test(NAME 33_test COMMAND 33)

add_executable(34 test/search-for-a-range.cpp)
target_link_libraries(34 lc)
target_link_libraries(34 gtest_main)
add_test(NAME 34_test COMMAND 34)

add_executable(35 test/search-insert-position.cpp)
target_link_libraries(35 lc)
target_link_libraries(35 gtest_main)
add_test(NAME 35_test COMMAND 35)

add_executable(36 test/valid-sudoku.cpp)
target_link_libraries(36 lc)
target_link_libraries(36 gtest_main)
add_test(NAME 36_test COMMAND 36)

add_executable(38 test/count-and-say.cpp)
target_link_libraries(38 lc)
target_link_libraries(38 gtest_main)
add_test(NAME 38_test COMMAND 38)

add_executable(41 test/first-missing-positive.cpp)
target_link_libraries(41 lc)
target_link_libraries(41 gtest_main)
add_test(NAME 41_test COMMAND 41)

add_executable(42 test/trapping-rain-water.cpp)
target_link_libraries(42 lc)
target_link_libraries(42 gtest_main)
add_test(NAME 42_test COMMAND 42)

add_executable(44 test/wildcard-matching.cpp)
target_link_libraries(44 lc)
target_link_libraries(44 gtest_main)
add_test(NAME 44_test COMMAND 44)

add_executable(46 test/permutations.cpp)
target_link_libraries(46 lc)
target_link_libraries(46 gtest_main)
add_test(NAME 46_test COMMAND 46)

add_executable(47 test/permutations-ii.cpp)
target_link_libraries(47 lc)
target_link_libraries(47 gtest_main)
add_test(NAME 47_test COMMAND 47)

add_executable(48 test/rotate-image.cpp)
target_link_libraries(48 lc)
target_link_libraries(48 gtest_main)
add_test(NAME 48_test COMMAND 48)

add_executable(49 test/group-anagrams.cpp)
target_link_libraries(49 lc)
target_link_libraries(49 gtest_main)
add_test(NAME 49_test COMMAND 49)

add_executable(58 test/length-of-last-word.cpp)
target_link_libraries(58 lc)
target_link_libraries(58 gtest_main)
add_test(NAME 58_test COMMAND 58)

add_executable(60 test/permutation-sequence.cpp)
target_link_libraries(60 lc)
target_link_libraries(60 gtest_main)
add_test(NAME 60_test COMMAND 60)

add_executable(61 test/rotate-list.cpp)
target_link_libraries(61 lc)
target_link_libraries(61 gtest_main)
add_test(NAME 61_test COMMAND 61)

add_executable(65 test/valid-number.cpp)
target_link_libraries(65 lc)
target_link_libraries(65 gtest_main)
add_test(NAME 65_test COMMAND 65)

add_executable(66 test/plus-one.cpp)
target_link_libraries(66 lc)
target_link_libraries(66 gtest_main)
add_test(NAME 66_test COMMAND 66)

add_executable(67 test/add-binary.cpp)
target_link_libraries(67 lc)
target_link_libraries(67 gtest_main)
add_test(NAME 67_test COMMAND 67)

add_executable(70 test/climbing-stairs.cpp)
target_link_libraries(70 lc)
target_link_libraries(70 gtest_main)
add_test(NAME 70_test COMMAND 70)

add_executable(71 test/simplify-path.cpp)
target_link_libraries(71 lc)
target_link_libraries(71 gtest_main)
add_test(NAME 71_test COMMAND 71)

add_executable(73 test/set-matrix-zeroes.cpp)
target_link_libraries(73 lc)
target_link_libraries(73 gtest_main)
add_test(NAME 73_test COMMAND 73)

add_executable(74 test/search-a-2d-matrix.cpp)
target_link_libraries(74 lc)
target_link_libraries(74 gtest_main)
add_test(NAME 74_test COMMAND 74)

add_executable(75 test/sort-colors.cpp)
target_link_libraries(75 lc)
target_link_libraries(75 gtest_main)
add_test(NAME 75_test COMMAND 75)

add_executable(77 test/combinations.cpp)
target_link_libraries(77 lc)
target_link_libraries(77 gtest_main)
add_test(NAME 77_test COMMAND 77)

add_executable(78 test/subsets.cpp)
target_link_libraries(78 lc)
target_link_libraries(78 gtest_main)
add_test(NAME 78_test COMMAND 78)

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

add_executable(84 test/largest-rectangle-in-histogram.cpp)
target_link_libraries(84 lc)
target_link_libraries(84 gtest_main)
add_test(NAME 84_test COMMAND 84)

add_executable(86 test/partition-list.cpp)
target_link_libraries(86 lc)
target_link_libraries(86 gtest_main)
add_test(NAME 86_test COMMAND 86)

add_executable(88 test/merge-sorted-array.cpp)
target_link_libraries(88 lc)
target_link_libraries(88 gtest_main)
add_test(NAME 88_test COMMAND 88)

add_executable(89 test/gray-code.cpp)
target_link_libraries(89 lc)
target_link_libraries(89 gtest_main)
add_test(NAME 89_test COMMAND 89)

add_executable(90 test/subsets-ii.cpp)
target_link_libraries(90 lc)
target_link_libraries(90 gtest_main)
add_test(NAME 90_test COMMAND 90)

add_executable(92 test/reverse-linked-list-ii.cpp)
target_link_libraries(92 lc)
target_link_libraries(92 gtest_main)
add_test(NAME 92_test COMMAND 92)

add_executable(94 test/binary-tree-inorder-traversal.cpp)
target_link_libraries(94 lc)
target_link_libraries(94 gtest_main)
add_test(NAME 94_test COMMAND 94)

add_executable(95 test/unique-binary-search-trees-ii.cpp)
target_link_libraries(95 lc)
target_link_libraries(95 gtest_main)
add_test(NAME 95_test COMMAND 95)

add_executable(96 test/unique-binary-search-trees.cpp)
target_link_libraries(96 lc)
target_link_libraries(96 gtest_main)
add_test(NAME 96_test COMMAND 96)

add_executable(98 test/validate-binary-search-tree.cpp)
target_link_libraries(98 lc)
target_link_libraries(98 gtest_main)
add_test(NAME 98_test COMMAND 98)

add_executable(99 test/recover-binary-search-tree.cpp)
target_link_libraries(99 lc)
target_link_libraries(99 gtest_main)
add_test(NAME 99_test COMMAND 99)

add_executable(100 test/same-tree.cpp)
target_link_libraries(100 lc)
target_link_libraries(100 gtest_main)
add_test(NAME 100_test COMMAND 100)

add_executable(101 test/symmetric-tree.cpp)
target_link_libraries(101 lc)
target_link_libraries(101 gtest_main)
add_test(NAME 101_test COMMAND 101)

add_executable(102 test/binary-tree-level-order-traversal.cpp)
target_link_libraries(102 lc)
target_link_libraries(102 gtest_main)
add_test(NAME 102_test COMMAND 102)

add_executable(103 test/binary-tree-zigzag-level-order-traversal.cpp)
target_link_libraries(103 lc)
target_link_libraries(103 gtest_main)
add_test(NAME 103_test COMMAND 103)

add_executable(104 test/maximum-depth-of-binary-tree.cpp)
target_link_libraries(104 lc)
target_link_libraries(104 gtest_main)
add_test(NAME 104_test COMMAND 104)

add_executable(105 test/construct-binary-tree-from-preorder-and-inorder-traversal.cpp)
target_link_libraries(105 lc)
target_link_libraries(105 gtest_main)
add_test(NAME 105_test COMMAND 105)

add_executable(106 test/construct-binary-tree-from-inorder-and-postorder-traversal.cpp)
target_link_libraries(106 lc)
target_link_libraries(106 gtest_main)
add_test(NAME 106_test COMMAND 106)

add_executable(107 test/binary-tree-level-order-traversal-ii.cpp)
target_link_libraries(107 lc)
target_link_libraries(107 gtest_main)
add_test(NAME 107_test COMMAND 107)

add_executable(108 test/convert-sorted-array-to-binary-search-tree.cpp)
target_link_libraries(108 lc)
target_link_libraries(108 gtest_main)
add_test(NAME 108_test COMMAND 108)

add_executable(109 test/convert-sorted-list-to-binary-search-tree.cpp)
target_link_libraries(109 lc)
target_link_libraries(109 gtest_main)
add_test(NAME 109_test COMMAND 109)

add_executable(110 test/balanced-binary-tree.cpp)
target_link_libraries(110 lc)
target_link_libraries(110 gtest_main)
add_test(NAME 110_test COMMAND 110)

add_executable(111 test/minimum-depth-of-binary-tree.cpp)
target_link_libraries(111 lc)
target_link_libraries(111 gtest_main)
add_test(NAME 111_test COMMAND 111)

add_executable(112 test/path-sum.cpp)
target_link_libraries(112 lc)
target_link_libraries(112 gtest_main)
add_test(NAME 112_test COMMAND 112)

add_executable(113 test/path-sum-ii.cpp)
target_link_libraries(113 lc)
target_link_libraries(113 gtest_main)
add_test(NAME 113_test COMMAND 113)

add_executable(114 test/flatten-binary-tree-to-linked-list.cpp)
target_link_libraries(114 lc)
target_link_libraries(114 gtest_main)
add_test(NAME 114_test COMMAND 114)

add_executable(116 test/populating-next-right-pointers-in-each-node.cpp)
target_link_libraries(116 lc)
target_link_libraries(116 gtest_main)
add_test(NAME 116_test COMMAND 116)

add_executable(117 test/populating-next-right-pointers-in-each-node-ii.cpp)
target_link_libraries(117 lc)
target_link_libraries(117 gtest_main)
add_test(NAME 117_test COMMAND 117)

add_executable(124 test/binary-tree-maximum-path-sum.cpp)
target_link_libraries(124 lc)
target_link_libraries(124 gtest_main)
add_test(NAME 124_test COMMAND 124)

add_executable(125 test/valid-palindrome.cpp)
target_link_libraries(125 lc)
target_link_libraries(125 gtest_main)
add_test(NAME 125_test COMMAND 125)

add_executable(126 test/word-ladder-ii.cpp)
target_link_libraries(126 lc)
target_link_libraries(126 gtest_main)
add_test(NAME 126_test COMMAND 126)

add_executable(127 test/word-ladder.cpp)
target_link_libraries(127 lc)
target_link_libraries(127 gtest_main)
add_test(NAME 127_test COMMAND 127)

add_executable(128 test/longest-consecutive-sequence.cpp)
target_link_libraries(128 lc)
target_link_libraries(128 gtest_main)
add_test(NAME 128_test COMMAND 128)

add_executable(129 test/sum-root-to-leaf-numbers.cpp)
target_link_libraries(129 lc)
target_link_libraries(129 gtest_main)
add_test(NAME 129_test COMMAND 129)

add_executable(130 test/surrounded-regions.cpp)
target_link_libraries(130 lc)
target_link_libraries(130 gtest_main)
add_test(NAME 130_test COMMAND 130)

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

add_executable(143 test/reorder-list.cpp)
target_link_libraries(143 lc)
target_link_libraries(143 gtest_main)
add_test(NAME 143_test COMMAND 143)

add_executable(144 test/binary-tree-preorder-traversal.cpp)
target_link_libraries(144 lc)
target_link_libraries(144 gtest_main)
add_test(NAME 144_test COMMAND 144)

add_executable(145 test/binary-tree-postorder-traversal.cpp)
target_link_libraries(145 lc)
target_link_libraries(145 gtest_main)
add_test(NAME 145_test COMMAND 145)

add_executable(146 test/lru-cache.cpp)
target_link_libraries(146 lc)
target_link_libraries(146 gtest_main)
add_test(NAME 146_test COMMAND 146)

add_executable(147 test/insertion-sort-list.cpp)
target_link_libraries(147 lc)
target_link_libraries(147 gtest_main)
add_test(NAME 147_test COMMAND 147)

add_executable(148 test/sort-list.cpp)
target_link_libraries(148 lc)
target_link_libraries(148 gtest_main)
add_test(NAME 148_test COMMAND 148)

add_executable(150 test/evaluate-reverse-polish-notation.cpp)
target_link_libraries(150 lc)
target_link_libraries(150 gtest_main)
add_test(NAME 150_test COMMAND 150)
