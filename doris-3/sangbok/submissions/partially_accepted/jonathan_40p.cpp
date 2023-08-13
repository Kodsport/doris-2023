#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    ll t, n;
    cin >> t >> n;
    if (n > 16) return 0;
    t *= 60;

    vector<ll> songs(n);
    for (auto &i: songs) cin >> i;

    ll best_count = 0, best_sum = 0;


    for (ll i = 0; i < (1 << n); ++i) {
        ll sum = 0, count = 0;
        for (ll j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += songs[j];
                ++count;
            }
        }
        if (sum <= t && count > best_count)
            best_sum = sum, best_count = count;
    }

    cout << best_sum << '\n';
}