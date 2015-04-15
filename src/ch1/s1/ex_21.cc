// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_21.h"

#include <limits>

using std::get;

namespace ch1 {
namespace s1 {
namespace ex21 {

Stats Process(const Data &data) {
    Ratio ratio {0};
    if (get<2>(data)) {
        ratio = static_cast<double>(get<1>(data)) / get<2>(data) * 1000;
    } else {
        ratio = std::numeric_limits<Ratio>::min();
    }
    Stats stats {get<0>(data), get<1>(data), get<2>(data), ratio};
    return stats;
}

}  // namespace ex21
}  // namespace s1
}  // namespace ch1
