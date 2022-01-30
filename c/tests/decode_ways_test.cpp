#include <gtest/gtest.h>

extern "C" {
#include "decode_ways.h"
}

TEST(decode_ways_test, numDecodings_91_1) {
    EXPECT_EQ(2, numDecodings_91_1("12"));
    EXPECT_EQ(3, numDecodings_91_1("226"));
    EXPECT_EQ(0, numDecodings_91_1("06"));
}
