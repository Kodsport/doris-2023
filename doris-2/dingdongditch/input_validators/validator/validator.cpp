#include "validator.h"

#include <cstring>
#include <string>

#include <cmath>
#include <iostream>
#include <regex>

void run() {
    int n_max = Arg("maxN", 200'000);
    int q_max = Arg("maxQ", 100'000);
    int all_or_one = Arg("allOrOne", 0);

    int n = Int(1, n_max);
    Space();
    int q = Int(1, q_max);
    Endl();
    vector<int> a = SpacedInts(n, 1, 1000'000'000);
    vector<int> b = SpacedInts(q, 1, n);

    if (set(a.begin(), a.end()).size() != a.size())
        die("Ai are not unique");
    if (all_or_one && !all_of(b.begin(), b.end(), [n](int i) { return i == 1 || i == n; }))
        die("allOrOne=1 but not all Bs are 0 or N");
    Eof();
}