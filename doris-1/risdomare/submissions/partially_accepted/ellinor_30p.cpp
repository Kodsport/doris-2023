#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N;
    cin >> N;

    string c;
    cin >> c;

    ll best_sum = 0;
    ll ans = 0;

    ll A, B;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        if (A + B > best_sum) {
            best_sum = A + B;
            ans = i;
        }
    }

    cout << ans + 1 << '\n';
}
