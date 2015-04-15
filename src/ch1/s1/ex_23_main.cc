// Copyright 2015 Samvel Khalatyan
//
#include "ch1/s1/ex_23.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using ch1::s1::ex23::BinarySearch;
using ch1::s1::ex23::Data;

using std::cin;
using std::cout;
using std::endl;

Data ReadData(std::string filename) {
    std::vector<int> data;
    int value;
    for (std::ifstream is {filename}; is >> value; ) {
        data.push_back(value);
    }
    return data;
}

bool Equal(int left, int right) {
    return left == right;
}

bool NotEqual(int left, int right) {
    return left != right;
}

int main(int argc, char *argv[]) {
    if (2 > argc) {
        cout << "missing data file" << endl;
    } else {
        Data data {ReadData(argv[1])};
        std::sort(data.begin(), data.end());
        using Checker = bool (*)(bool);
        bool (*checker)(bool);
        if (2 < argc and '-' == argv[2][0]) {
            checker = [](bool v) -> bool { return v; };
        } else {
            checker = [](bool v) -> bool { return not v; };
        }
        for (int value; cin >> value; ) {
            if (checker(BinarySearch(value, data))) {
                cout << value << endl;
            }
        }
    }
    return 0;
}
