#include <gtest/gtest.h>

TEST(hello_eon, eon_init) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
}