#include "validator.h"

#include <cmath>
#include <cstring>
#include <string>

using ll = long long;

void run() {
    ll n_max = Arg("nMax");

    string s = Line();
    ll n = stoll(s);

    if (n < 1 || n > 1'000'000'000'000'000'000)
        die("n is out of range");
    if (s[0] == '0')
        die("leading zeros are not allowed");
    double d = stod(s);
    if (floor(d) != d)
        die("non integers are not allowed");

    Eof();
}