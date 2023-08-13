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
    if (!max(0.0, c - f))
        return {0, 1};
    pll ans = {1e18, 1e18};
    for (ll b = 1; b <= 1e6; ++b) {
        double x = max(0.0, c - f);
        ll lo = floor(x * b), hi = ceil(x * b);
        if (close_enough({lo, b}, c, f))
            ans = min(ans, {lo, b});
        if (close_enough({hi, b}, c, f))
            ans = min(ans, {hi, b});
        if (close_enough(ans, c, f) && ans.first != (ll) 1e18)
            break;
    }
    return ans;
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
