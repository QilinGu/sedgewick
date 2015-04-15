// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_21.h"

#include <cmath>
#include <limits>
#include <ostream>
#include <tuple>

using ch1::s1::ex21::Data;

// must be place before Google Test
std::ostream &operator <<(std::ostream &os, const Data &data) {
    os << std::get<1>(data);
    os << ' ' << std::get<2>(data);
    return os;
}

#include "gtest/gtest.h"

using ch1::s1::ex21::Process;
using ch1::s1::ex21::Ratio;
using ch1::s1::ex21::Stats;
using std::get;

TEST(Process, NullData) {
    Data data {"John", 0, 0};
    Stats stats {Process(data)};
    EXPECT_STREQ(get<0>(data).c_str(), get<0>(stats).c_str());
    EXPECT_EQ(get<1>(data), get<1>(stats));
    EXPECT_EQ(get<2>(data), get<2>(stats));
    EXPECT_DOUBLE_EQ(get<3>(stats), std::numeric_limits<Ratio>::min());
}

TEST(Process, DataOne) {
    Data data {"John", 1, 1};
    Stats stats {Process(data)};
    EXPECT_STREQ(get<0>(data).c_str(), get<0>(stats).c_str());
    EXPECT_EQ(get<1>(data), get<1>(stats));
    EXPECT_EQ(get<2>(data), get<2>(stats));
    EXPECT_DOUBLE_EQ(get<3>(stats), 1000);
}

TEST(Process, DataRatio) {
    Data data {"John", 0, 0};
    for (int i {1}; i < 10; ++i) {
        get<1>(data) = i;
        for (int j {1}; j < 10; ++j) {
            get<2>(data) = j;
            Stats stats {Process(data)};
            EXPECT_STREQ(get<0>(data).c_str(), get<0>(stats).c_str());
            EXPECT_EQ(get<1>(data), get<1>(stats));
            EXPECT_EQ(get<2>(data), get<2>(stats));
            Ratio ratio {1000 * get<1>(data) / get<2>(data)};
            EXPECT_DOUBLE_EQ(get<3>(stats), ratio) << data;
        }
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
