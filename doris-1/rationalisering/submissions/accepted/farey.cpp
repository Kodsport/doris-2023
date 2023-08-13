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

pll farey(double x, double precision, ll lim) {
    ll a = 0, b = 1, c = 1, d = 1, ac = a + c, bd = b + d;
    double m;
    while (1) {
        ac = a + c;
        bd = b + d;
        if (close_enough({ac, bd}, x, precision) || ((ac > lim) | (bd > lim))) {
            break;
        }
        m = (double) ac / bd;
        if (x > m) {
            a = ac;
            b = bd;
        } else {
            c = ac;
            d = bd;
        }
    }
    pll ans = {ac, bd};

    if (close_enough({a, b}, x, precision))
        ans = min(ans, {a, b});

    if (close_enough({c, d}, x, precision))
        ans = min(ans, {c, d});
    return ans;
}

pll solve(double c, double f) {
    if (!max(0.0, c - f))
        return {0, 1};
    pll r = farey(c - floor(c), f, 1'000'000);
    r.first += static_cast<ll>(c) * r.second;
    return r;
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
