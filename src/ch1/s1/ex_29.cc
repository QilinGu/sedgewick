// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_29.h"

namespace {

const int *BinarySearch(int value, const int *data, size_t size) {
    if (not size) {
        return nullptr;
    }
    const int *pivot {data + size / 2};
    if (value == *pivot) {
        return pivot;
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
namespace ex29 {

size_t Count(int value, const std::vector<int> &array) {
    size_t counts {0};
    if (const int *item {::BinarySearch(value, array.data(), array.size())}) {
        ++counts;
        for (; item > array.data() and *(item - 1) == *item; ) {
            ++counts;
            --item;
        }
        for (item += counts; item < &*array.end() and *(item - 1) == *item; ) {
            ++counts;
            ++item;
        }
    }
    return counts;
}

size_t Rank(int value, const std::vector<int> &array) {
    if (const int *item {::BinarySearch(value, array.data(), array.size())}) {
        while (item > array.data() and *(item - 1) == *item) {
            --item;
        }
        return item - array.data();
    }
    return 0;
}

}  // namespace ex29
}  // namespace s1
}  // namespace ch1
