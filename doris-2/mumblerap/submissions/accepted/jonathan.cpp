#include <algorithm>
#include <iostream>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);
    string s;
    getline(cin, s);
    getline(cin, s);
    ll curr = 0;
    ll max = 0;
    for (char c: s) {
        if ('0' <= c && c <= '9') {
            curr = curr * 10 + c - '0';
            max = std::max(max, curr);
        } else {
            curr = 0;
        }
    }
    cout << max << '\n';
}