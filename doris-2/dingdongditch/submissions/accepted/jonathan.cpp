#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    vector<pair<ll, ll>> b(q);
    for (auto &i: a) cin >> i;

    for (ll i = 0; i < q; ++i)
        b[i].second = i;
    for (auto &i: b) cin >> i.first;


    sort(begin(a), end(a));
    sort(begin(b), end(b));

    ll idx = 0;
    ll sum = 0;
    vector<ll> ans(q);
    for (auto i: b) {
        while (idx < i.first)
            sum += a[idx++];
        ans[i.second] = sum;
    }
    for (auto i: ans)
        cout << i << '\n';
}