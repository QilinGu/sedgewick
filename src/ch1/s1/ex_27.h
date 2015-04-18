// Copyright 2015 Samvel Khalatyan

#ifndef CH1_S1_EX_27_H_
#define CH1_S1_EX_27_H_

#include <cstddef>
#include <utility>

namespace ch1 {
namespace s1 {
namespace ex27 {

// first element is the binomial coefficient
// second one is the number of calls to calculate coefficients
using Stats = std::pair<int, size_t>;

Stats Binomial(int n, int k);
Stats QuickBinomial(int n, int k);

}  // namespace ex27
}  // namespace s1
}  // namespace ch1

#endif  // CH1_S1_EX_27_H_
