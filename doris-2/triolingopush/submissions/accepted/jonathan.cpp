#include <array>
#include <iostream>

using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr ull MOD = 1000'000'007;
struct value {
    ull a, b;
};

struct coefficients {
    ull aa, ab, ac, ba, bb, bc;
};

value apply(value x, coefficients c) {
    return {(x.a * c.aa + x.b * c.ab + c.ac) % MOD,
            (x.a * c.ba + x.b * c.bb + c.bc) % MOD};
}

coefficients doubled(coefficients c) {
    return {(c.aa * c.aa + c.ab * c.ba) % MOD, (c.aa * c.ab + c.ab * c.bb) % MOD, (c.aa * c.ac + c.ab * c.bc + c.ac) % MOD,
            (c.ba * c.aa + c.bb * c.ba) % MOD, (c.bb * c.bb + c.ba * c.ab) % MOD, (c.ba * c.ac + c.bb * c.bc + c.bc) % MOD};
}

ull solve(ull n) {
    if (n <= 2) return n;
    static const std::array<coefficients, 64> cs = []() {
        std::array<coefficients, 64> cs{};
        cs[0] = {0, 1, 0, 1, 1, 1};
        for (int i = 1; i < 64; ++i)
            cs[i] = doubled(cs[i - 1]);
        return cs;
    }();

    value v = {1, 2};
    for (ull i = 0; i < 64; ++i)
        if ((n - 2) & (1ull << i))
            v = apply(v, cs[i]);
    return v.b;
}

ull brute(ull n) {
    if (n <= 2) return n;
    n -= 2;
    ull a = 1, b = 2;
    while (n--) {
        ull c = (a + b + 1) % MOD;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    ull n;
    cin >> n;
    std::cout << solve(n) << '\n';
}