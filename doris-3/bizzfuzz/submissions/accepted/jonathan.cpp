#include <algorithm>
#include <iostream>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll l = lcm(c, d);
    string out;
    cout << b / l - (a - 1) / l << '\n';
}