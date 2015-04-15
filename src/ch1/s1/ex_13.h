// Copyright 2015 Samvel Khalatyan

#ifndef CH1_S1_EX_13_H_
#define CH1_S1_EX_13_H_

#include <vector>

namespace ch1 {
namespace s1 {
namespace ex13 {

using Row = std::vector<int>;
using Matrix = std::vector<Row>;

// Transposes a non-empty matrix otherwise returns empty matrix
//
//  Matrix data {{1, 2, 3}, {4, 5, 6}};
//  Matrix result {Transpose(data)};
Matrix Transpose(const Matrix &);

}  // namespace ex13
}  // namespace s1
}  // namespace ch1

#endif   // CH1_S1_EX_13_H_
