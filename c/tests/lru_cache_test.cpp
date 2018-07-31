#include <gtest/gtest.h>

extern "C" {
#include "lru_cache.h"
}

TEST(lru_cache_test, lru_cache) {
    LRUCache *cache = lRUCacheCreate(2);
    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 2);
    EXPECT_EQ(lRUCacheGet(cache, 1), 1);
    lRUCachePut(cache, 3, 3);
    EXPECT_EQ(lRUCacheGet(cache, 2), -1);
    lRUCachePut(cache, 4, 4);
    EXPECT_EQ(lRUCacheGet(cache, 1), -1);
    EXPECT_EQ(lRUCacheGet(cache, 3), 3);
    EXPECT_EQ(lRUCacheGet(cache, 4), 4);
    lRUCacheFree(cache);
}
