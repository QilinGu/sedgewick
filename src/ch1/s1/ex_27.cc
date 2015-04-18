// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_27.h"

#include <boost/functional/hash.hpp>
#include <cstddef>
#include <unordered_map>
#include <utility>

using std::pair;
using std::unordered_map;

namespace {

class BinomialImpl {
public:
    BinomialImpl(int n, int k) {
        coefficient_ = Calculate(n, k);
    }
    operator int() const {
        return coefficient_;
    }
    size_t calls() const {
        return calls_;
    }

private:
    double Calculate(int n, int k) {
        if (not n and not k) {
            return 1;
        }
        if (n < 0 or k < 0) {
            return 0;
        }
        ++calls_;
        return Calculate(n - 1, k) + Calculate(n - 1, k - 1);
    }

private:
    size_t calls_ {0};
    int coefficient_ {0};
};

using Coefficient = pair<int, int>;

class CoefficientHash {
public:
    size_t operator()(const Coefficient &coefficient) const {
        return boost::hash_value(coefficient);
    }
};

class QuickBinomialImpl {
public:
    QuickBinomialImpl(int n, int k) {
        coefficient_ = Calculate(n, k);
    }
    operator int() const {
        return coefficient_;
    }
    size_t calls() const {
        return calls_;
    }

private:
    double Calculate(int n, int k) {
        if (not n and not k) {
            return 1;
        }
        if (n < 0 or k < 0) {
            return 0;
        }
        if (cache_.end() == cache_.find({n, k})) {
            ++calls_;
            cache_[{n, k}] = Calculate(n - 1, k) + Calculate(n - 1, k - 1);
        }
        return cache_[{n, k}];
    }

private:
    using Cache = unordered_map<Coefficient, int, CoefficientHash>;

private:
    size_t calls_ {0};
    int coefficient_ {0};
    Cache cache_;
};

}  // namespace

namespace ch1 {
namespace s1 {
namespace ex27 {

Stats Binomial(int n, int k) {
    ::BinomialImpl coefficient {n, k};
    Stats stats {coefficient, coefficient.calls()};
    return stats;
}

Stats QuickBinomial(int n, int k) {
    ::QuickBinomialImpl coefficient {n, k};
    Stats stats {coefficient, coefficient.calls()};
    return stats;
}

}  // namespace ex27
}  // namespace s1
}  // namespace ch1
