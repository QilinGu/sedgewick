#include "ch1/s1/fwd.h"

#include "gtest/gtest.h"

#include <cstddef>
#include <initializer_list>
#include <string>
#include <utility>

using namespace ch1_s1;

TEST(BinaryString, Numbers) {
    using TItem = std::pair<size_t, std::string>;
    using TData = std::initializer_list<TItem>;
    TData data {
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
    for(auto &d : data) {
        std::string bin_str {BinaryString(d.first)};
        EXPECT_STREQ(bin_str.c_str(), d.second.c_str()) << d.first;
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
