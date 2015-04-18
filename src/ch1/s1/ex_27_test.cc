// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_27.h"

#include "gtest/gtest.h"

using ch1::s1::ex27::Binomial;
using ch1::s1::ex27::QuickBinomial;
using ch1::s1::ex27::Stats;

TEST(Binomial, Negative) {
    EXPECT_EQ(Binomial(-1, 0).first, 0);
    EXPECT_EQ(Binomial(0, -1).first, 0);
    EXPECT_EQ(Binomial(-1, -1).first, 0);
}

TEST(Binomial, Coefficients) {
    EXPECT_EQ(Binomial(0, 0).first, 1);
    EXPECT_EQ(Binomial(1, 0).first, 1);
    EXPECT_EQ(Binomial(1, 1).first, 1);
    EXPECT_EQ(Binomial(2, 0).first, 1);
    EXPECT_EQ(Binomial(2, 1).first, 2);
    EXPECT_EQ(Binomial(2, 2).first, 1);
    EXPECT_EQ(Binomial(3, 0).first, 1);
    EXPECT_EQ(Binomial(3, 1).first, 3);
    EXPECT_EQ(Binomial(3, 2).first, 3);
    EXPECT_EQ(Binomial(3, 3).first, 1);
    EXPECT_EQ(Binomial(4, 0).first, 1);
    EXPECT_EQ(Binomial(4, 1).first, 4);
    EXPECT_EQ(Binomial(4, 2).first, 6);
    EXPECT_EQ(Binomial(4, 3).first, 4);
    EXPECT_EQ(Binomial(4, 4).first, 1);
    EXPECT_EQ(Binomial(5, 0).first, 1);
    EXPECT_EQ(Binomial(5, 1).first, 5);
    EXPECT_EQ(Binomial(5, 2).first, 10);
    EXPECT_EQ(Binomial(5, 3).first, 10);
    EXPECT_EQ(Binomial(5, 4).first, 5);
    EXPECT_EQ(Binomial(5, 5).first, 1);
    EXPECT_EQ(Binomial(6, 0).first, 1);
    EXPECT_EQ(Binomial(6, 1).first, 6);
    EXPECT_EQ(Binomial(6, 2).first, 15);
    EXPECT_EQ(Binomial(6, 3).first, 20);
    EXPECT_EQ(Binomial(6, 4).first, 15);
    EXPECT_EQ(Binomial(6, 5).first, 6);
    EXPECT_EQ(Binomial(6, 6).first, 1);
}

TEST(QuickBinomial, Negative) {
    EXPECT_EQ(QuickBinomial(-1, 0).first, 0);
    EXPECT_EQ(QuickBinomial(0, -1).first, 0);
    EXPECT_EQ(QuickBinomial(-1, -1).first, 0);
}

TEST(QuickBinomial, Coefficients) {
    EXPECT_EQ(QuickBinomial(0, 0).first, 1);
    EXPECT_EQ(QuickBinomial(1, 0).first, 1);
    EXPECT_EQ(QuickBinomial(1, 1).first, 1);
    EXPECT_EQ(QuickBinomial(2, 0).first, 1);
    EXPECT_EQ(QuickBinomial(2, 1).first, 2);
    EXPECT_EQ(QuickBinomial(2, 2).first, 1);
    EXPECT_EQ(QuickBinomial(3, 0).first, 1);
    EXPECT_EQ(QuickBinomial(3, 1).first, 3);
    EXPECT_EQ(QuickBinomial(3, 2).first, 3);
    EXPECT_EQ(QuickBinomial(3, 3).first, 1);
    EXPECT_EQ(QuickBinomial(4, 0).first, 1);
    EXPECT_EQ(QuickBinomial(4, 1).first, 4);
    EXPECT_EQ(QuickBinomial(4, 2).first, 6);
    EXPECT_EQ(QuickBinomial(4, 3).first, 4);
    EXPECT_EQ(QuickBinomial(4, 4).first, 1);
    EXPECT_EQ(QuickBinomial(5, 0).first, 1);
    EXPECT_EQ(QuickBinomial(5, 1).first, 5);
    EXPECT_EQ(QuickBinomial(5, 2).first, 10);
    EXPECT_EQ(QuickBinomial(5, 3).first, 10);
    EXPECT_EQ(QuickBinomial(5, 4).first, 5);
    EXPECT_EQ(QuickBinomial(5, 5).first, 1);
    EXPECT_EQ(QuickBinomial(6, 0).first, 1);
    EXPECT_EQ(QuickBinomial(6, 1).first, 6);
    EXPECT_EQ(QuickBinomial(6, 2).first, 15);
    EXPECT_EQ(QuickBinomial(6, 3).first, 20);
    EXPECT_EQ(QuickBinomial(6, 4).first, 15);
    EXPECT_EQ(QuickBinomial(6, 5).first, 6);
    EXPECT_EQ(QuickBinomial(6, 6).first, 1);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
