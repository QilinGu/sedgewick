// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_28.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ch1::s1::ex28::RemoveDuplicates;
using ::testing::ElementsAre;

using Array = std::vector<int>;

TEST(RemoveDuplicates, EmptyArray) {
    Array array {};
    array = RemoveDuplicates(array);
    EXPECT_THAT(array, ElementsAre());
}

TEST(RemoveDuplicates, SingleElement) {
    Array array {1};
    array = RemoveDuplicates(array);
    EXPECT_THAT(array, ElementsAre(1));
}

TEST(RemoveDuplicates, Array1) {
    Array array {1, 2, 2, 2, 3, 5};
    array = RemoveDuplicates(array);
    EXPECT_THAT(array, ElementsAre(1, 2, 3, 5));
}

TEST(RemoveDuplicates, Array2) {
    Array array {1, 1, 2, 4, 4, 6, 8, 8};
    array = RemoveDuplicates(array);
    EXPECT_THAT(array, ElementsAre(1, 2, 4, 6, 8));
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
