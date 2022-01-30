#include <gtest/gtest.h>

extern "C" {
#include "restore_ip_addresses.h"
}

TEST(restore_ip_addresses_test, restoreIpAddresses_93_1) {
    char *s1 = strdup("25525511135");
    int returnSize1 = 0;
    std::vector<std::string> expected1{"255.255.11.135", "255.255.111.35"};
    char **actual1 = restoreIpAddresses_93_1(s1, &returnSize1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], actual1[i]);
        free(actual1[i]);
    }
    free(actual1);
    free(s1);

    char *s2 = strdup("0000");
    int returnSize2 = 0;
    std::vector<std::string> expected2{"0.0.0.0"};
    char **actual2 = restoreIpAddresses_93_1(s2, &returnSize2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], actual2[i]);
        free(actual2[i]);
    }
    free(actual2);
    free(s2);

    char *s3 = strdup("101023");
    int returnSize3 = 0;
    std::vector<std::string> expected3{"1.0.10.23", "1.0.102.3", "10.1.0.23",
                                       "10.10.2.3", "101.0.2.3"};
    char **actual3 = restoreIpAddresses_93_1(s3, &returnSize3);
    ASSERT_EQ(expected3.size(), returnSize3);
    for (int i = 0; i < returnSize3; ++i) {
        EXPECT_EQ(expected3[i], actual3[i]);
        free(actual3[i]);
    }
    free(actual3);
    free(s3);
}

TEST(restore_ip_addresses_test, restoreIpAddresses_93_2) {
    char *s1 = strdup("25525511135");
    int returnSize1 = 0;
    std::vector<std::string> expected1{"255.255.11.135", "255.255.111.35"};
    char **actual1 = restoreIpAddresses_93_2(s1, &returnSize1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], actual1[i]);
        free(actual1[i]);
    }
    free(actual1);
    free(s1);

    char *s2 = strdup("0000");
    int returnSize2 = 0;
    std::vector<std::string> expected2{"0.0.0.0"};
    char **actual2 = restoreIpAddresses_93_2(s2, &returnSize2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], actual2[i]);
        free(actual2[i]);
    }
    free(actual2);
    free(s2);

    char *s3 = strdup("101023");
    int returnSize3 = 0;
    std::vector<std::string> expected3{"1.0.10.23", "1.0.102.3", "10.1.0.23",
                                       "10.10.2.3", "101.0.2.3"};
    char **actual3 = restoreIpAddresses_93_2(s3, &returnSize3);
    ASSERT_EQ(expected3.size(), returnSize3);
    for (int i = 0; i < returnSize3; ++i) {
        EXPECT_EQ(expected3[i], actual3[i]);
        free(actual3[i]);
    }
    free(actual3);
    free(s3);
}
