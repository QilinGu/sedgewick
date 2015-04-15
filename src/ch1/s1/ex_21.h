// Copyright 2015 Samvel Khalatyan

#ifndef CH1_S1_EX_21_H_
#define CH1_S1_EX_21_H_

#include <string>
#include <tuple>

namespace ch1 {
namespace s1 {
namespace ex21 {

using Data = std::tuple<std::string, int, int>;
using Ratio = int;
using Stats = std::tuple<std::string, int, int, Ratio>;

// Calculates ratio of last two columns up to 3 decimal places.  Divide the
// ratio by 1000. to get floating point value: long int guarantees consistency
// in results:
//
//      Data data {"John", 1, 3};
//      Stats stats {Process(data)};  //=> {"John", 1, 3, 1333}
Stats Process(const Data &);

}  // namespace ex21
}  // namespace s1
}  // namespace ch1

#endif  // CH1_S1_EX_21_H_
