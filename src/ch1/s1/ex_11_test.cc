// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_11.h"

#include <sstream>

#include "gtest/gtest.h"

using ch1::s1::ex11::operator <<;

TEST(BoolMatrix, Output) {
    BoolMatrix matrix {
          {true, false, true}
        , {false, true, false}
        , {false, false, false}
        , {true, true, true}};
    std::ostringstream os;
    os << matrix;
    const char *str {os.str().c_str();
    EXPECT_STREQ(str, "0,0*0,1 0,2*1,0 1,1*1,2 2,0 2,1 2,2 3,0*3,1*3,2*");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
