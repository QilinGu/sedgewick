// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_13.h"

#include <cstddef>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ch1::s1::ex13::Matrix;
using ch1::s1::ex13::Transpose;

using ::testing::ElementsAre;

TEST(TransponseMatrix, EmptyMatrix) {
    Matrix source;
    Matrix result {Transpose(source)};
    EXPECT_TRUE(result.empty());
}

TEST(TransponseMatrix, ColumnVector) {
    Matrix source {{1}, {2}, {3}};
    Matrix result {Transpose(source)};
    EXPECT_FALSE(result.empty());
    EXPECT_EQ(result.size(), static_cast<size_t>(1));
    EXPECT_THAT(result[0], ElementsAre(1, 2, 3));
}

TEST(TransponseMatrix, RowVector) {
    Matrix source {{1, 2, 3}};
    Matrix result {Transpose(source)};
    EXPECT_FALSE(result.empty());
    EXPECT_EQ(result.size(), static_cast<size_t>(3));
    EXPECT_THAT(result[0], ElementsAre(1));
    EXPECT_THAT(result[1], ElementsAre(2));
    EXPECT_THAT(result[2], ElementsAre(3));
}

TEST(TransponseMatrix, DoubleTransposeColumnVector) {
    Matrix source {{1}, {2}, {3}};
    Matrix tmp {Transpose(source)};
    Matrix result {Transpose(tmp)};
    EXPECT_FALSE(result.empty());
    EXPECT_EQ(result.size(), static_cast<size_t>(3));
    EXPECT_THAT(result[0], ElementsAre(1));
    EXPECT_THAT(result[1], ElementsAre(2));
    EXPECT_THAT(result[2], ElementsAre(3));
}

TEST(TransponseMatrix, DoubleTransposeRowVector) {
    Matrix source {{1, 2, 3}};
    Matrix tmp {Transpose(source)};
    Matrix result {Transpose(tmp)};
    EXPECT_FALSE(result.empty());
    EXPECT_EQ(result.size(), static_cast<size_t>(1));
    EXPECT_THAT(result[0], ElementsAre(1, 2, 3));
}

TEST(TransponseMatrix, Matrix2x3) {
    Matrix source {{1, 2, 3}, {4, 5, 6}};
    Matrix result {Transpose(source)};
    EXPECT_FALSE(result.empty());
    EXPECT_EQ(result.size(), static_cast<size_t>(3));
    EXPECT_THAT(result[0], ElementsAre(1, 4));
    EXPECT_THAT(result[1], ElementsAre(2, 5));
    EXPECT_THAT(result[2], ElementsAre(3, 6));
}

TEST(TransponseMatrix, Matrix3x2) {
    Matrix source {{1, 2}, {3, 4}, {5, 6}};
    Matrix result {Transpose(source)};
    EXPECT_FALSE(result.empty());
    EXPECT_EQ(result.size(), static_cast<size_t>(2));
    EXPECT_THAT(result[0], ElementsAre(1, 3, 5));
    EXPECT_THAT(result[1], ElementsAre(2, 4, 6));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
