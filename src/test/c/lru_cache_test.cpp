#include <gtest/gtest.h>

extern "C" {
#include <lru_cache.h>
}

TEST(leetcode_146, normal) {
    LRUCache *cache = lRUCacheCreate(2);
    lRUCachePut(cache, 2, 1);
    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 3);
    lRUCachePut(cache, 4, 1);
    EXPECT_EQ(lRUCacheGet(cache, 1), -1);
    EXPECT_EQ(lRUCacheGet(cache, 2), 3);
    lRUCacheFree(cache);
}
