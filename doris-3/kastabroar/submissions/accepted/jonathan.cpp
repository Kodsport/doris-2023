#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

using ll = long long;

ll e[100'001]{};

ll find(ll a) {
    return e[a] < 0 ? a : e[a] = find(e[a]);
}

bool same(ll a, ll b) {
    return find(a) == find(b);
}

void join(ll a, ll b) {
    a = find(a), b = find(b);

    if (a == b) return;

    if (e[a] > e[b]) swap(a, b);

    e[a] += e[b], e[b] = a;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    memset(e, -1, sizeof(e));

    ll n, m;
    cin >> n >> m;

    if (m + 1 < n) {
        cout << "Nej\n";
        return 0;
    }

    vector<array<ll, 2>> extra;

    while (m--) {
        ll a, b;
        cin >> a >> b;
        if (same(a, b))
            extra.push_back({a, b});
        else
            join(a, b);
    }

    vector<ll> from_component;

    {
        bool visited[100'001]{};
        for (ll i = 1; i < n + 1; ++i) {

            ll parent = find(i);

            if (visited[parent])
                continue;
            else
                visited[parent] = true, from_component.push_back(parent);
        }
    }

    cout << "Ja\n";
    cout << from_component.size() - 1 << '\n';
    for (ll i = 1, j = 0; i < from_component.size(); ++i, ++j) {
        cout << extra[j][0] << ' ' << extra[j][1] << ' ' << from_component[0] << ' ' << from_component[i] << '\n';
    }
}