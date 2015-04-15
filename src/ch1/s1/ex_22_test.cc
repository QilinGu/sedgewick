// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_22.h"

#include "gtest/gtest.h"

using ch1::s1::ex22::BinarySearch;

TEST(BinarySearch, SingleElement) {
    int array[] {1};
    BinarySearch search(array, sizeof(array) / sizeof(array[0]));
    EXPECT_EQ(search(0), nullptr);
    EXPECT_EQ(search(1), array);
    EXPECT_EQ(search(2), nullptr);
}

TEST(BinarySearch, TwoElements) {
    int array[] {1, 3};
    BinarySearch search(array, sizeof(array) / sizeof(array[0]));
    EXPECT_EQ(search(0), nullptr);
    EXPECT_EQ(search(1), array);
    EXPECT_EQ(search(2), nullptr);
    EXPECT_EQ(search(3), array + 1);
    EXPECT_EQ(search(4), nullptr);
}

TEST(BinarySearch, ThreeElements) {
    int array[] {1, 3, 5};
    BinarySearch search(array, sizeof(array) / sizeof(array[0]));
    EXPECT_EQ(search(0), nullptr);
    EXPECT_EQ(search(1), array);
    EXPECT_EQ(search(2), nullptr);
    EXPECT_EQ(search(3), array + 1);
    EXPECT_EQ(search(4), nullptr);
    EXPECT_EQ(search(5), array + 2);
    EXPECT_EQ(search(6), nullptr);
}

TEST(BinarySearch, SeveralElements) {
    int array[] {2, 3, 5, 8, 10, 12, 13, 14};
    BinarySearch search(array, sizeof(array) / sizeof(array[0]));
    EXPECT_EQ(search(array[0]), array);
    for (size_t index {1}; index < search.size(); ++index) {
        for (int value {array[index - 1] + 1}; value < array[index]; ++value) {
            EXPECT_EQ(search(value), nullptr);
        }
        EXPECT_EQ(search(array[index]), array + index);
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
