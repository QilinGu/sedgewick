// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_29.h"

#include "gtest/gtest.h"

using ch1::s1::ex29::Count;
using ch1::s1::ex29::Rank;

TEST(Count, EmptyArray) {
    std::vector<int> data {};
    EXPECT_EQ(Count(0, data), static_cast<size_t>(0));
    EXPECT_EQ(Count(1, data), static_cast<size_t>(0));
}

TEST(Count, Array) {
    std::vector<int> data {1, 1, 2, 3, 3, 3, 5, 6, 6};
    EXPECT_EQ(Count(0, data), static_cast<size_t>(0));
    EXPECT_EQ(Count(1, data), static_cast<size_t>(2));
    EXPECT_EQ(Count(2, data), static_cast<size_t>(1));
    EXPECT_EQ(Count(3, data), static_cast<size_t>(3));
    EXPECT_EQ(Count(4, data), static_cast<size_t>(0));
    EXPECT_EQ(Count(5, data), static_cast<size_t>(1));
    EXPECT_EQ(Count(6, data), static_cast<size_t>(2));
}

TEST(Rank, EmptyArray) {
    std::vector<int> data {};
    EXPECT_EQ(Rank(0, data), static_cast<size_t>(0));
    EXPECT_EQ(Rank(1, data), static_cast<size_t>(0));
}

TEST(Rank, Array) {
    std::vector<int> data {1, 1, 2, 2, 3, 4};
    EXPECT_EQ(Rank(1, data), static_cast<size_t>(0));
    EXPECT_EQ(Rank(2, data), static_cast<size_t>(2));
    EXPECT_EQ(Rank(3, data), static_cast<size_t>(4));
    EXPECT_EQ(Rank(4, data), static_cast<size_t>(5));
}

TEST(RankAndCount, Array) {
    std::vector<int> array {1, 2, 2, 2, 3, 5, 5};
    for (auto &test : {1, 2, 3, 5}) {
        size_t rank {Rank(test, array)};
        size_t count {Count(test, array)};
        auto iter = array.begin() + rank;
        for (auto end = iter + count; iter < end; ++iter) {
            EXPECT_EQ(*iter, test);
        }
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
