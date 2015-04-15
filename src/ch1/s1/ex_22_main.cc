// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_22.h"

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::setw;
using std::vector;

using ch1::s1::ex22::BinarySearch;

ostream &operator<<(ostream &os, const BinarySearch::Stats &stats) {
    return os << stats.first << ' ' << stats.second;
}

ostream &operator<<(ostream &os, const BinarySearch::Trace &trace) {
    size_t indent {0};
    for (auto &stats : trace) {
        if (indent++) {
            os << endl;
        }
        os << setw(indent) << ' ';
        os << stats;
    }
    return os;
}

ostream &operator<<(ostream &os, const vector<int> &data) {
    for (auto x : data) {
        os << ' ' << x;
    }
    return os;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "missing array numeric elements" << endl;
    } else {
        vector<int> array;
        array.reserve(argc - 1);
        for (int index {1}; index < argc; ++index) {
            int value {atoi(argv[index])};
            array.push_back(value);
        }
        cout << "array:" << array << endl;
        cout << endl;
        BinarySearch search(array.data(), array.size());
        cout << "input value in range (0, 100): ";
        for (int value {0}; cin >> value; ) {
            BinarySearch::Rank rank {search(value)};
            if (rank == -1) {
                cout << "missing" << endl;
            } else {
                cout << "found at " << rank << endl;
            }
            cout << "trace:" << endl;
            cout << search.trace() << endl;
            cout << "input value in range (0, 100): ";
        }
    }
    return 0;
}
