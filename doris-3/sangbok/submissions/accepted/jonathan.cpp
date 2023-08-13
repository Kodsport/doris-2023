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
    t *= 60;

    vector<ll> songs(n);
    for (auto &i: songs) cin >> i;

    sort(begin(songs), end(songs));

    ll sum = 0;
    for (auto i: songs) {
        sum += -(sum + i <= t) & i;
    }

    cout << sum << '\n';
}