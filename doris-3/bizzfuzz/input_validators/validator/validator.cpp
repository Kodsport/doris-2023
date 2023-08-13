#include "validator.h"
#include <cmath>
#include <cstring>
#include <sstream>
#include <string_view>

typedef long long ll;
using pll = pair<ll, ll>;

void run() {
	ll max_b = Arg("max_b", 1e18);
	ll max_range = Arg("max_range", 1e18);
	int d_is_2_c = Arg("d_is_2_c", 0);
	int ac_is_1 = Arg("ac_is_1", 0);

	istringstream inp1{Line()};

	string as, bs, cs, ds;
	inp1 >> as >> bs >> cs >> ds;


	if (as.find("0") == 0)
			die("leading zero added to a");
	if (bs.find("0") == 0)
			die("leading zero added to b");
	if (cs.find("0") == 0)
			die("leading zero added to c");
	if (ds.find("0") == 0)
			die("leading zero added to d");

	ll a = stoll(as), b = stoll(bs), c = stoll(cs), d = stoll(ds);
	if (a < 1 || a >= b) {
			die("a is out of range");
	}
	if (b < 1 || b > max_b) {
			die("b is out of range");
	}
	if (c < 1 || c >= b) {
			die("c is out of range");
	}
	if (d < 1 || d >= b) {
			die("d is out of range");
	}
	if (b - a > max_range) {
			die("range is out of range");
	}
	if (d_is_2_c && d != 2 * c) {
			die("d is not 2*c");
	}
	if (ac_is_1 && a != 1) {
			die("a is not 1");
	}
	if (ac_is_1 && c != 1) {
			die("c is not 1");
	}
}
