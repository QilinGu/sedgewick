// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_15.h"

namespace ch1 {
namespace s1 {
namespace ex15 {

Data Histogram(const Data &data, const size_t bins) {
    Data hist(bins, 0);
    for (auto x : data) {
        if (x < bins) {
            ++hist[x];
        }
    }
    return std::move(hist);
}

}  // namespace ex15
}  // namespace s1
}  // namespace ch1
