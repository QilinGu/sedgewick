// Copyright 2015 Samvel Khalatyan

#include "ch1/s1/ex_27.h"

#include <cstring>
#include <iomanip>
#include <iostream>
#include <locale>

using ch1::s1::ex27::Stats;
using ch1::s1::ex27::Binomial;
using ch1::s1::ex27::QuickBinomial;

using std::cin;
using std::cout;
using std::endl;
using std::locale;
using std::ostream;
using std::setw;

ostream &operator<<(ostream &os, const Stats &stats) {
    return os << setw(15) << stats.first << ' ' << setw(15) << stats.second;
}

int main(int argc, char *argv[]) {
    Stats (*Factory)(int, int) {Binomial}
    if (1 < argc) {
        if (0 == strcmp(argv[1], "--quick")) {
            Factory = QuickBinomial;
        } else {
            cout << "usage: " << argv[0] << " [--quick]" << endl;
            return 0;
        }
    }
    locale loc("");
    cout.imbue(loc);
    for (int n, k; cin >> n >> k; ) {
        Stats stats {Factory(n, k)};
        cout << setw(3) << n << ' ' << setw(3) << k << ' ' << stats << endl;
    }
    return 0;
}
