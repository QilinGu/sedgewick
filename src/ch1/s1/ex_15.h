// Copyright 2015 Samvel Khalatyan

#ifndef CH1_S1_EX_15_H_
#define CH1_S1_EX_15_H_

#include <cstddef>
#include <vector>

namespace ch1 {
namespace s1 {
namespace ex15 {

using Data = std::vector<size_t>;

// Creates a histogram of requested length from an array of data
Data Histogram(const Data &, const size_t /*bins*/);

}  // namespace ex15
}  // namespace s1
}  // namespace ch1

#endif  // CH1_S1_EX_15_H_
