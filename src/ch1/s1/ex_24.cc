// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_24.h"

namespace ch1 {
namespace s1 {
namespace ex24 {

size_t GreatestCommonDivisor(size_t left, size_t right) {
    if (not right) {
        return left;
    }
    left %= right;
    return GreatestCommonDivisor(right, left);
}

}  // namespace ex24
}  // namespace s1
}  // namespace ch1
