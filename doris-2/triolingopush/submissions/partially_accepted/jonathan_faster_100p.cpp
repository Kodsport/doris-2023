#include <iostream>

using namespace std;

using ll = long long;
using ull = unsigned long long;


// vv python code that finds the constants used for the optimization
/*
#!/bin/env python3

for k in range(1, 100):
    a = 10**100
    b = 10**200
    for _ in range(k):
        c = a + b + 1
        a = b
        b = c

    c1 = (a // 10**100 % 10**50)
    c2 = (a // 10**200 % 10**50)
    c3 = (a % 10**50)

    c4 = (b // 10**100 % 10**50)
    c5 = (b // 10**200 % 10**50)
    c6 = (b % 10**50)

    mult = max(c1 + c2, c4 + c5)
    if mult * (10**9+7) + max(c3, c6) >= 2**64-1:
        break
    print("\r", end='')
    print(f"k={k} a2={c1}*a+{c2}*b+{c3}, b2={c4}*a+{c5}*b+{c6}", end='')

print('')
*/
// ^^ python code that finds the constants used for the optimization

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
        while (n > 48) { // do 48 iterations at once, if we do more than 48 we might get overflow, see python code
            ull a2 = 2971215073 * a + 4807526976 * b + 7778742048, b2 = 4807526976 * a + 7778742049 * b + 12586269024;
            a = a2 % 1000'000'007;
            b = b2 % 1000'000'007;
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