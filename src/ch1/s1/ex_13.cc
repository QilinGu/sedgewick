// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_13.h"

#include <cstddef>
#include <memory>

namespace ch1 {
namespace s1 {
namespace ex13 {

Matrix Transpose(const Matrix &source) {
    Matrix result;
    if (not source.empty() and not source[0].empty()) {
        const size_t kRows {source.size()};
        const size_t kCols {source[0].size()};
        std::unique_ptr<int[]> data {new int[kRows * kCols]};
        for (size_t row {0}; row < kRows; ++row) {
            const auto &row_vector = source[row];
            for (size_t col {0}; col < kCols; ++col) {
                *(data.get() + col * kRows + row) = row_vector[col];
            }
        }
        result.resize(kCols);
        for (size_t row {0}; row < kCols; ++row) {
            auto &row_vector = result[row];
            row_vector.resize(kRows);
            for (size_t col {0}; col < kRows; ++col) {
                row_vector[col] = *(data.get() + row * kRows + col);
            }
        }
    }
    return std::move(result);
}

}  // namespace ex13
}  // namespace s1
}  // namespace ch1
