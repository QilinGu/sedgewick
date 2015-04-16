// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_24.h"

#include <cstddef>
#include <iostream>

using ch1::s1::ex24::GreatestCommonDivisor;

using std::cin;
using std::cout;
using std::endl;

int main(int, char *[]) {
    for (size_t first, second; cin >> first >> second; ) {
        cout << first;
        cout << ' ' << second;
        cout << " > " << GreatestCommonDivisor(first, second) << endl;
    }
    return 0;
}
