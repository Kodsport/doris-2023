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
    ll a = 1, b = 2;
    if (n <= 2) {
        cout << n << '\n';
    } else {
        n -= 2;
        while (n--) {
            ll c = (a + b + 1) % 1000'000'007;
            a = b;
            b = c;
        }
        cout << b << '\n';
    }
}