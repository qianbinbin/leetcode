#include <gtest/gtest.h>

extern "C" {
#include "restore_ip_addresses.h"
}

TEST(restore_ip_addresses_test, restoreIpAddresses_93_1) {
    int size = 0;
    char **addresses = restoreIpAddresses_93_1("25525511135", &size);
    for (int i = 0; i < size; ++i) {
        puts(addresses[i]);
        free(addresses[i]);
    }
    free(addresses);
}

TEST(restore_ip_addresses_test, restoreIpAddresses_93_2) {
    int size = 0;
    char **addresses = restoreIpAddresses_93_2("25525511135", &size);
    for (int i = 0; i < size; ++i) {
        puts(addresses[i]);
        free(addresses[i]);
    }
    free(addresses);
}
