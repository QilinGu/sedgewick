// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_14.h"

#include <cmath>

#include "gtest/gtest.h"

using ch1::s1::ex14::Lg;

TEST(Lg, Numbers) {
    for (int value {0}; value < 17; ++value) {
        EXPECT_EQ(Lg(value), static_cast<int>(log2(value))) << value;
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
