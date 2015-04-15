// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_15.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::ch1::s1::ex15::Data;
using ::ch1::s1::ex15::Histogram;
using ::testing::ElementsAre;

TEST(Histogram, EmptyData) {
    Data data;
    Data hist {Histogram(data, 5)};
    EXPECT_THAT(hist, ElementsAre(0, 0, 0, 0, 0));
}

TEST(Histogram, EmptyHistogram) {
    Data data {1, 2, 3, 4, 5};
    Data hist {Histogram(data, 0)};
    EXPECT_TRUE(hist.empty());
}

TEST(Histogram, Data) {
    Data data {1, 2, 3, 4, 5};
    Data hist {Histogram(data, 3)};
    EXPECT_THAT(hist, ElementsAre(0, 1, 1));
    hist = Histogram(data, 6);
    EXPECT_THAT(hist, ElementsAre(0, 1, 1, 1, 1, 1));
    hist = Histogram({1, 2, 3, 2, 4, 1, 1}, 5);
    EXPECT_THAT(hist, ElementsAre(0, 3, 2, 1, 1));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
