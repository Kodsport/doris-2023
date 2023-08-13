#include <iostream>

using namespace std;

using ll = long long;

ll dp[1000'001]{};

ll f(ll n) {
    if (n <= 2) return n;
    if (!dp[n]) dp[n] = (f(n - 1) + f(n - 2) + 1) % 1000'000'007;
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    ll n;
    cin >> n;
    cout << f(n) << endl;
}