// Copyright 2015 Samvel Khalatyan

#ifndef CH1_S1_EX_22_H_
#define CH1_S1_EX_22_H_

#include <cstddef>
#include <list>
#include <utility>

namespace ch1 {
namespace s1 {
namespace ex22 {

// finds a value in the array using binary search algorithm:
//
//      int array[] {1, 3, 5, 7};
//      size_t size {sizeof(array) / sizeof(array[0])};
//      BinarySearch search {array, 0, size};
//      const int *element {search(5)};
//
// trace() accessor must return the search trace
class BinarySearch {
public:
    using Stats = std::pair<size_t, size_t>;
    using Trace = std::list<Stats>;

public:
    BinarySearch(const int *array, size_t size)
        : kArray_ {array}
        , kSize_ {size}
    {}
    size_t size() const {
        return kSize_;
    }
    const int *operator()(int value) {
        trace_.clear();
        return Find(value, 0, kSize_);
    }
    const Trace &trace() const {
        return trace_;
    }

private:
    const int *Find(int value, size_t lo, size_t hi);

private:
    const int *const kArray_;
    const size_t kSize_;
    Trace trace_;
};

}  // namespace ex22
}  // namespace s1
}  // namespace ch1

#endif  // CH1_S1_EX_22_H_
