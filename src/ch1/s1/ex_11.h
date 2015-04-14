// Copyright 2015 Samvel Khalatyan

#ifndef CH1_S1_EX_11_H_
#define CH1_S1_EX_11_H_

#include <iosfwd>
#include <vector>

namespace ch1 {
namespace s1 {
namespace ex11 {

using BoolMatrix = std::vector<std::vector<bool>>;
// print 2D bool array including row and col numbers:
//      substitute '*' for every true and ' ' for every false
std::ostream &operator <<(std::ostream &, const BoolMatrix &);

}  // namespace ex11
}  // namespace s1
}  // namespace ch1

#endif  // CH1_S1_EX_11_H_
