#include <gtest/gtest.h>

extern "C" {
#include <restore-ip-addresses.h>
}

TEST(leetcode_93, normal) {
    int size = 0;
    char **addresses = restoreIpAddresses_93("010010", &size);
    for (int i = 0; i < size; ++i) {
        puts(addresses[i]);
        free(addresses[i]);
    }
    free(addresses);
}
