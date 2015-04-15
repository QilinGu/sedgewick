// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_22.h"


namespace ch1 {
namespace s1 {
namespace ex22 {

const int *BinarySearch::Find(int value, size_t lo, size_t hi) {
    trace_.push_back({lo, hi});
    if (lo >= hi) {
        return nullptr;
    }
    const int *pivot {kArray_ + lo + (hi - lo) / 2};
    if (value == *pivot) {
        return pivot;
    } else if (value < *pivot) {
        return Find(value, lo, pivot - kArray_);
    } else {
        return Find(value, pivot - kArray_ + 1, hi);
    }
}

}  // namespace ex22
}  // namespace s1
}  // namespace ch1
