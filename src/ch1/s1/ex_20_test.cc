// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_20.h"

#include <cmath>
#include <limits>

#include "gtest/gtest.h"

using ch1::s1::ex20::Ln;

TEST(Ln, Zero) {
    EXPECT_DOUBLE_EQ(Ln(0), std::numeric_limits<double>::min());
}

TEST(Ln, One) {
    EXPECT_DOUBLE_EQ(Ln(1), 0.);
}

TEST(Ln, Number) {
    for (size_t i {2}; i < 10; ++i) {
        double result {0};
        for (size_t j {i}; j > 1; --j) {
            result += log2(j);
        }
        EXPECT_DOUBLE_EQ(Ln(i), result);
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
