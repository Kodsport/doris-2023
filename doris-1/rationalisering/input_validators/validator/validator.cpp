#include "validator.h"
#include <cmath>
#include <cstring>
#include <sstream>
#include <string_view>

typedef long long ll;
using pll = pair<ll, ll>;

/*
max_val = int(cmdlinearg("max_val", 10**6))
b_is_1000 = int(cmdlinearg("b_is_1000", 0))
dec_f_exp_by = int(cmdlinearg("dec_f_exp_by", 0))
*/

int num_sig_digs(string_view s) {
    auto first_sig_dig = s.find_first_not_of("0.");
    if (first_sig_dig == string_view::npos)
        return 1;
    int ans = s.size() - first_sig_dig;
    if (s.substr(first_sig_dig).find('.') != string_view::npos)
        ans -= 1;
    return ans;
}


double diff(pll r, double c) {
    return abs(static_cast<double>(r.first) / static_cast<double>(r.second) - c);
}

bool close_enough(pll r, double c, double f) {
    return diff(r, c) <= f + 1e-9;
}

pll solve(double c, double f) {
    if (!max(0.0, c - f))
        return {0, 1};
    pll ans = {1e18, 1e18};
    for (ll b = 1; b <= 1e6; ++b) {
        double x = max(0.0, c - f);
        ll lo = floor(x * b), hi = ceil(x * b);
        if (close_enough({lo, b}, c, f))
            ans = min(ans, {lo, b});
        if (close_enough({hi, b}, c, f))
            ans = min(ans, {hi, b});
        if (close_enough(ans, c, f) && ans.first != (ll) 1e18)
            break;
    }
    return ans;
}


void run() {
    assert(num_sig_digs("0.01") == 1);
    assert(num_sig_digs("0.01234") == 4);
    assert(num_sig_digs("0.0222") == 3);
    assert(num_sig_digs("0") == 1);
    assert(num_sig_digs("5.1") == 2);

    int max_val = Arg("max_val", 1e6);
    int b_is_1000 = Arg("b_is_1000", 0);
    int dec_f_exp_by = Arg("dec_f_exp_by", 0);

    istringstream inp{Line()};

    string cs, fs;
    inp >> cs >> fs;

    double c = stod(cs), f = stod(fs);
    if (c < 0 || c > 10)
        die("c is out of range");
    if (f < 1e-8 || f > 1e-1)
        die("f is out of range");
    if (num_sig_digs(cs) > 6)
        die("c has too many significant digits");
    if (num_sig_digs(fs) > 6)
        die("c has too many significant digits");
    if (fs.back() == '0' && f != 0)
        die("trailing zero added to f");
    if (cs.back() == '0' && c != 0)
        die("trailing zero added to c");
    if (fs.find("00") == 0)
        die("leading zero added to f");
    if (cs.find("00") == 0)
        die("leading zero added to c");

    auto [a, b] = solve(c, f);
    if (b_is_1000 && b != 1000) {
        die("b_is_1000 requirement not satisfied, " + cs + " " + fs);
    }
    if (a > max_val)
        die("a too big, (" + to_string(a) + ">" + to_string(max_val) + ")");
    if (b > max_val)
        die("b too big, (" + to_string(b) + ">" + to_string(max_val) + ")");
}