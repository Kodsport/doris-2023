#include <iostream>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    ll n;
    cin >> n;
    ull a = 1, b = 2;
    if (n <= 2) {
        cout << n << '\n';
    } else {
        n -= 2;

        // vv optimization
        while (n > 48) {
#pragma GCC unroll(48) // GCC doesnt unroll the loop without this D: (clang does though)
            for (int i = 0; i < 48; ++i) {
                ull c = (a + b + 1); // avoid doing expensive modulo computation every iteration
                a = b;
                b = c;
            }
            a %= 1000'000'007;
            b %= 1000'000'007;

            n -= 48;
        }
        // ^^ optimization

        while (n--) {
            ull c = (a + b + 1) % 1000'000'007;
            a = b;
            b = c;
        }
        cout << b << '\n';
    }
}