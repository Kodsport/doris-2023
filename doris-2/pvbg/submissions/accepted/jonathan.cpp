#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);
    ll n;
    cin >> n;
    ll ans = 1e18;
    while (n--) {
        ll temp;
        cin >> temp;
        if (temp < ans)
            ans = temp;
    }
    cout << ans + 1 << '\n';
}