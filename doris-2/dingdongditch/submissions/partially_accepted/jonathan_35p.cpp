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

    // O(qn^2) but it gives 55p because C++ is fast

    ll n, q;
    cin >> n >> q;
    vector<int> a(n), b(q);
    for (auto &i: a) cin >> i;
    for (auto &i: b) cin >> i;
    for (auto lim: b) {
        vector<int> smallest;
        for (auto e: a) {
            smallest.push_back(e);
            for (size_t i = smallest.size(); i-- > 1;) {
                if (smallest[i] < smallest[i - 1]) {
                    swap(smallest[i], smallest[i - 1]);
                }
            }
            if (smallest.size() > lim) smallest.pop_back();
        }
        ll sum = 0;
        for (auto e: smallest) {
            sum += e;
        }
        cout << sum << '\n';
    }
}