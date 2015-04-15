// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_14.h"

#include <limits>

namespace ch1 {
namespace s1 {
namespace ex14 {

// returns min interger value if value is invlid log argument
int Lg(int value) {
    if (value <= 0) {
        return std::numeric_limits<int>::min();
    }
    int result {0};
    while (value >>= 1) {
        ++result;
    }
    return result;
}

}  // namespace ex14
}  // namespace s1
}  // namespace ch1
