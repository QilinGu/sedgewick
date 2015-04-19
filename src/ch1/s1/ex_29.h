// Copyright 2015 Samvel Khalatyan

#ifndef CH1_S1_EX_29_H_
#define CH1_S1_EX_29_H_

#include <cstddef>
#include <vector>

namespace ch1 {
namespace s1 {
namespace ex29 {

// counts a number of elements in sorted array that are equal to the value
size_t Count(int value, const std::vector<int> &array);

// finds a number of elements in sorted array that are smaller than the value
size_t Rank(int value, const std::vector<int> &array);

}  // namespace ex29
}  // namespace s1
}  // namespace ch1

#endif  // CH1_S1_EX_29_H_
