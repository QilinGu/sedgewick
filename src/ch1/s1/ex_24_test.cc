// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_24.h"

#include "gtest/gtest.h"

using ch1::s1::ex24::GreatestCommonDivisor;

TEST(GreatestCommonDivisor, Zero) {
    EXPECT_EQ(GreatestCommonDivisor(0, 0), static_cast<size_t>(0));
    EXPECT_EQ(GreatestCommonDivisor(1, 0), static_cast<size_t>(1));
    EXPECT_EQ(GreatestCommonDivisor(2, 0), static_cast<size_t>(2));
    EXPECT_EQ(GreatestCommonDivisor(0, 1), static_cast<size_t>(1));
    EXPECT_EQ(GreatestCommonDivisor(0, 2), static_cast<size_t>(2));
}

TEST(GreatestCommonDivisor, NonZero) {
    EXPECT_EQ(GreatestCommonDivisor(9, 12), static_cast<size_t>(3));
    EXPECT_EQ(GreatestCommonDivisor(18, 6), static_cast<size_t>(6));
    EXPECT_EQ(GreatestCommonDivisor(24, 108), static_cast<size_t>(12));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
