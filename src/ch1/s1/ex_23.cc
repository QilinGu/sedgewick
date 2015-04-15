// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_23.h"

#include <cstddef>

namespace {

bool BinarySearch(int value, const int *data, size_t size) {
    if (not size) {
        return false;
    }
    const int *pivot {data + size / 2};
    if (value == *pivot) {
        return true;
    } else if (value < *pivot) {
        return BinarySearch(value, data, pivot - data);
    } else {
        ++pivot;
        return BinarySearch(value, pivot, (data + size) - pivot);
    }
}

}  // namespace

namespace ch1 {
namespace s1 {
namespace ex23 {

bool BinarySearch(int value, const Data &data) {
    return ::BinarySearch(value, data.data(), data.size());
}

}  // namespace ex23
}  // namespace s1
}  // namespace ch1
