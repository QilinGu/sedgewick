// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_28.h"

#include <cstddef>

namespace ch1 {
namespace s1 {
namespace ex28 {

// function relies on compiler that returns an r-value
std::vector<int> RemoveDuplicates(const std::vector<int> &array) {
    if (1 > array.size()) {
        return std::vector<int> {};
    }
    std::vector<int> result;
    result.reserve(array.size());
    result.push_back(array[0]);
    for (size_t i {1}; i < array.size(); ++i) {
        if (array[i] != array[i - 1]) {
            result.push_back(array[i]);
        }
    }
    return result;
}

}  // namespace ex28
}  // namespace s1
}  // namespace ch1
