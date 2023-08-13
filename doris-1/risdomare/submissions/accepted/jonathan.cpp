#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    int n;
    cin >> n;
    string choice;
    cin >> choice;
    int mostimp = -1;
    if (choice == "antal") mostimp = 0;
    if (choice == "storlek") mostimp = 1;

    // sum, most important, idx
    tuple<int, int, int> best{};

    for (int i = 0; i < n; ++i) {
        int q[2];
        cin >> q[0] >> q[1];
        best = max(best, tuple{q[0] + q[1], q[mostimp], i + 1});
    }
    cout << get<2>(best) << '\n';
}