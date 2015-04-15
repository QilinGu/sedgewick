// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_23.h"

#include "gtest/gtest.h"

using ch1::s1::ex23::BinarySearch;
using ch1::s1::ex23::Data;

TEST(BinarySearch, SingleElement) {
    Data array {1};
    EXPECT_FALSE(BinarySearch(0, array));
    EXPECT_TRUE(BinarySearch(1, array));
    EXPECT_FALSE(BinarySearch(2, array));
}

TEST(BinarySearch, TwoElements) {
    Data array {1, 3};
    EXPECT_FALSE(BinarySearch(0, array));
    EXPECT_TRUE(BinarySearch(1, array));
    EXPECT_FALSE(BinarySearch(2, array));
    EXPECT_TRUE(BinarySearch(3, array));
    EXPECT_FALSE(BinarySearch(4, array));
}

TEST(BinarySearch, ThreeElements) {
    Data array {1, 3, 5};
    EXPECT_FALSE(BinarySearch(0, array));
    EXPECT_TRUE(BinarySearch(1, array));
    EXPECT_FALSE(BinarySearch(2, array));
    EXPECT_TRUE(BinarySearch(3, array));
    EXPECT_FALSE(BinarySearch(4, array));
    EXPECT_TRUE(BinarySearch(5, array));
    EXPECT_FALSE(BinarySearch(6, array));
}

TEST(BinarySearch, SeveralElements) {
    Data array {2, 3, 5, 8, 10, 12, 13, 14};
    EXPECT_TRUE(BinarySearch(array[0], array));
    for (size_t index {1}; index < array.size(); ++index) {
        for (int value {array[index - 1] + 1}; value < array[index]; ++value) {
            EXPECT_FALSE(BinarySearch(value, array));
        }
        EXPECT_TRUE(BinarySearch(array[index], array));
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
