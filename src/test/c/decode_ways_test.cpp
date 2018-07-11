#include <gtest/gtest.h>

extern "C" {
#include "decode_ways.h"
}

TEST(decode_ways_test, numDecodings_91_1) {
    EXPECT_EQ(numDecodings_91_1("12"), 2);
    EXPECT_EQ(numDecodings_91_1("226"), 3);
}
