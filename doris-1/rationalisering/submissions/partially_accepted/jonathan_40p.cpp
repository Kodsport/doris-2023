#include <cmath>
#include <iostream>

using namespace std;

using ll = int64_t;

using pll = pair<ll, ll>;

double diff(pll r, double c) {
    return abs(static_cast<double>(r.first) / static_cast<double>(r.second) - c);
}

bool close_enough(pll r, double c, double f) {
    return diff(r, c) <= f;
}

pll solve(double c, double f) {
    for (ll a = 0; a <= 1e3; ++a) {
        for (ll b = 1; b <= 1e3; ++b) {
            if (close_enough({a, b}, c, f)) {
                return {a, b};
            }
        }
    }
    return {0, 1000};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    double c, f;
    cin >> c >> f;
    auto r = solve(c, f);
    cout << r.first << '\n' << r.second << '\n';
}
