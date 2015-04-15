// Copyright 2015 Samvel Khalatyan

#include <iostream>
#include <string>
#include <tuple>

#include "ch1/s1/ex_21.h"

using std::cin;
using std::cout;
using std::endl;
using std::get;
using std::ostream;
using ch1::s1::ex21::Data;
using ch1::s1::ex21::Process;
using ch1::s1::ex21::Stats;

ostream &operator<<(ostream &os, const Stats &stats) {
    os << get<0>(stats);
    os << ' ' << get<1>(stats);
    os << ' ' << get<2>(stats);
    os << ' ' << get<3>(stats);
    return os;
}

int main(int, char *[]) {
    std::string name;
    int column_one;
    int column_two;
    for (Data data; cin >> name >> column_one >> column_two; ) {
        get<0>(data) = name;
        get<1>(data) = column_one;
        get<2>(data) = column_two;
        Stats stats {Process(data)};
        cout << stats << endl;
    }
    return 0;
}
