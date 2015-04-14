// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_9.h"

#include <cstddef>
#include <initializer_list>
#include <string>
#include <utility>

#include "gtest/gtest.h"

using ch1::s1::ex9::BinaryString;

TEST(BinaryString, Numbers) {
    using Item = std::pair<size_t, std::string>;
    using Data = std::initializer_list<Item>;
    Data data {
          {0, "0"}
        , {1, "1"}
        , {2, "10"}
        , {3, "11"}
        , {4, "100"}
        , {5, "101"}
        , {6, "110"}
        , {7, "111"}
        , {8, "1000"}
        , {9, "1001"}
        , {10, "1010"}
        , {11, "1011"}
        , {12, "1100"}
        , {13, "1101"}
        , {14, "1110"}
        , {15, "1111"}
    };
    for (auto &item : data) {
        std::string representation {BinaryString(item.first)};
        EXPECT_STREQ(representation.c_str(), item.second.c_str()) << item.first;
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
