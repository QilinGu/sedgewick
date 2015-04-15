// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_20.h"

#include <cmath>

#include <limits>

namespace ch1 {
namespace s1 {
namespace ex20 {

// method is recursive
double Ln(size_t value) {
    if (not value) {
        return std::numeric_limits<double>::min();
    }
    if (value == 1) {
        return 0.;
    }
    return log2(value) + Ln(value - 1);
}

}  // namespace ex20
}  // namespace s1
}  // namespace ch1
