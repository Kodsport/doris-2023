#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

auto solve(double c, double f) {
    double a = 0, b = 1;
    while (true) {
        if (a / b < c - f)
            ++a;
        else if (a / b > c + f)
            ++b;
        else
            return pair{a, b};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    double c, f;
    cin >> c >> f;
    auto [a, b] = solve(c, f);
    cout << a << '\n'
         << b << '\n';
}
